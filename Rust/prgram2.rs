use image::{self, GenericImageView};
use ndarray::{Array2, Array4, ArrayView2, ArrayView4, Axis};
use rand::distributions::Distribution;
use rand::thread_rng;
use rand_distr::Normal;
use rayon::prelude::*;
use std::path::Path;

struct ConvLayer {
    filters: Array4<f32>,
    biases: Vec<f32>,
}

struct MaxPoolLayer {
    pool_size: usize,
}

struct BatchNormLayer {
    gamma: Vec<f32>,
    beta: Vec<f32>,
    epsilon: f32,
}

struct DenseLayer {
    weights: Array2<f32>,
    biases: Vec<f32>,
    dropout_rate: f32,
}

struct CNN {
    conv1: ConvLayer,
    bn1: BatchNormLayer,
    conv2: ConvLayer,
    bn2: BatchNormLayer,
    conv3: ConvLayer,
    bn3: BatchNormLayer,
    pool1: MaxPoolLayer,
    conv4: ConvLayer,
    bn4: BatchNormLayer,
    pool2: MaxPoolLayer,
    dense1: DenseLayer,
    dense2: DenseLayer,
}

impl ConvLayer {
    fn new(num_filters: usize, channels: usize, filter_size: usize) -> Self {
        let scale = (2.0 / (channels * filter_size * filter_size) as f32).sqrt();
        let normal = Normal::new(0.0, scale).unwrap();
        let mut rng = thread_rng();

        let filters =
            Array4::from_shape_fn((num_filters, channels, filter_size, filter_size), |_| {
                normal.sample(&mut rng)
            });

        let biases = vec![0.0; num_filters];
        ConvLayer { filters, biases }
    }

    fn forward(&self, input: &ArrayView4<f32>) -> Array4<f32> {
        let (batch_size, channels, height, width) = input.dim();
        let (num_filters, _, filter_size, _) = self.filters.dim();
        let output_height = height - filter_size + 1;
        let output_width = width - filter_size + 1;

        let mut output =
            Array4::<f32>::zeros((batch_size, num_filters, output_height, output_width));

        // Parallelize batch processing
        output
            .axis_iter_mut(Axis(0))
            .enumerate()
            .par_bridge()
            .for_each(|(b, mut batch)| {
                for f in 0..num_filters {
                    for h in 0..output_height {
                        for w in 0..output_width {
                            let mut sum = self.biases[f];
                            // Optimized convolution
                            for c in 0..channels {
                                for i in 0..filter_size {
                                    for j in 0..filter_size {
                                        sum += input[[b, c, h + i, w + j]]
                                            * self.filters[[f, c, i, j]];
                                    }
                                }
                            }
                            batch[[f, h, w]] = sum.max(0.0); // ReLU activation
                        }
                    }
                }
            });

        output
    }
}

impl MaxPoolLayer {
    fn new(pool_size: usize) -> Self {
        MaxPoolLayer { pool_size }
    }

    fn forward(&self, input: &ArrayView4<f32>) -> Array4<f32> {
        let (batch_size, channels, height, width) = input.dim();
        let output_height = height / self.pool_size;
        let output_width = width / self.pool_size;
        let mut output = Array4::<f32>::zeros((batch_size, channels, output_height, output_width));

        for b in 0..batch_size {
            for c in 0..channels {
                for h in 0..output_height {
                    for w in 0..output_width {
                        let mut max_val = f32::MIN;
                        for i in 0..self.pool_size {
                            for j in 0..self.pool_size {
                                let val =
                                    input[[b, c, h * self.pool_size + i, w * self.pool_size + j]];
                                max_val = max_val.max(val);
                            }
                        }
                        output[[b, c, h, w]] = max_val;
                    }
                }
            }
        }
        output
    }
}

impl BatchNormLayer {
    fn new(num_features: usize) -> Self {
        BatchNormLayer {
            gamma: vec![1.0; num_features],
            beta: vec![0.0; num_features],
            epsilon: 1e-5,
        }
    }

    fn forward(&self, input: &ArrayView4<f32>) -> Array4<f32> {
        let mut output = input.to_owned();
        let (batch_size, channels, height, width) = input.dim();

        for c in 0..channels {
            let mut mean = 0.0;
            let mut var = 0.0;
            let n = batch_size * height * width;

            // Calculate mean
            for b in 0..batch_size {
                for h in 0..height {
                    for w in 0..width {
                        mean += input[[b, c, h, w]];
                    }
                }
            }
            mean /= n as f32;

            // Calculate variance
            for b in 0..batch_size {
                for h in 0..height {
                    for w in 0..width {
                        let diff = input[[b, c, h, w]] - mean;
                        var += diff * diff;
                    }
                }
            }
            var /= n as f32;

            // Normalize
            for b in 0..batch_size {
                for h in 0..height {
                    for w in 0..width {
                        output[[b, c, h, w]] = self.gamma[c] * (input[[b, c, h, w]] - mean)
                            / (var + self.epsilon).sqrt()
                            + self.beta[c];
                    }
                }
            }
        }
        output
    }
}

impl DenseLayer {
    fn new(input_size: usize, output_size: usize, dropout_rate: f32) -> Self {
        let normal = Normal::new(0.0, (2.0 / input_size as f32).sqrt()).unwrap();
        let mut rng = thread_rng();

        let weights = Array2::from_shape_fn((output_size, input_size), |_| {
            normal.sample(&mut rng) as f32
        });

        let biases = vec![0.0; output_size];
        DenseLayer {
            weights,
            biases,
            dropout_rate,
        }
    }

    fn forward(&self, input: &ArrayView2<f32>) -> Array2<f32> {
        let mut output = input.dot(&self.weights.t());

        // Add biases
        for i in 0..output.nrows() {
            for j in 0..output.ncols() {
                output[[i, j]] += self.biases[j];
            }
        }

        // Apply dropout during training
        let mut rng = thread_rng();
        let uniform = rand::distributions::Uniform::new(0.0, 1.0);

        output.mapv_inplace(|x| {
            if uniform.sample(&mut rng) < self.dropout_rate {
                0.0
            } else {
                x.max(0.0) / (1.0 - self.dropout_rate)
            }
        });

        output
    }
}

impl CNN {
    fn new() -> Self {
        CNN {
            conv1: ConvLayer::new(32, 1, 3),
            bn1: BatchNormLayer::new(32),
            conv2: ConvLayer::new(64, 32, 3),
            bn2: BatchNormLayer::new(64),
            conv3: ConvLayer::new(128, 64, 3),
            bn3: BatchNormLayer::new(128),
            pool1: MaxPoolLayer::new(2),
            conv4: ConvLayer::new(256, 128, 3),
            bn4: BatchNormLayer::new(256),
            pool2: MaxPoolLayer::new(2),
            dense1: DenseLayer::new(256 * 4 * 4, 512, 0.4),
            dense2: DenseLayer::new(512, 10, 0.0),
        }
    }

    fn forward(&self, input: &Array4<f32>) -> Array2<f32> {
        // First block
        let conv1 = self.conv1.forward(&input.view());
        let bn1 = self.bn1.forward(&conv1.view());

        // Second block
        let conv2 = self.conv2.forward(&bn1.view());
        let bn2 = self.bn2.forward(&conv2.view());
        let pool1 = self.pool1.forward(&bn2.view());

        // Third block
        let conv3 = self.conv3.forward(&pool1.view());
        let bn3 = self.bn3.forward(&conv3.view());

        // Fourth block
        let conv4 = self.conv4.forward(&bn3.view());
        let bn4 = self.bn4.forward(&conv4.view());
        let pool2 = self.pool2.forward(&bn4.view());

        // Dense layers
        let (batch_size, channels, height, width) = pool2.dim();
        let flattened = pool2
            .into_shape((batch_size, channels * height * width))
            .unwrap();

        let dense1 = self.dense1.forward(&flattened.view());
        let dense2 = self.dense2.forward(&dense1.view());

        // Improved Softmax
        let mut output = dense2;
        output.axis_iter_mut(Axis(0)).for_each(|mut row| {
            let max = row.fold(f32::MIN, |a, &b| a.max(b));
            let sum: f32 = row.mapv(|x| (x - max).exp()).sum();
            row.mapv_inplace(|x| ((x - max).exp()) / sum);
        });

        output
    }
}

fn load_and_preprocess_image(path: &str) -> Result<Array4<f32>, Box<dyn std::error::Error>> {
    let img = image::open(Path::new(path))?;
    let gray_img = img.to_luma8();

    // Better resizing with proper antialiasing
    let resized =
        image::imageops::resize(&gray_img, 28, 28, image::imageops::FilterType::CatmullRom);

    // Improved normalization and preprocessing
    let mut image_array = Array4::<f32>::zeros((1, 1, 28, 28));
    let mut sum = 0.0;
    let mut sum_sq = 0.0;

    // Calculate mean and variance
    for y in 0..28 {
        for x in 0..28 {
            let val = resized.get_pixel(x, y)[0] as f32 / 255.0;
            sum += val;
            sum_sq += val * val;
            image_array[[0, 0, y as usize, x as usize]] = val;
        }
    }

    let n = 784.0; // 28*28
    let mean = sum / n;
    let var = (sum_sq / n) - (mean * mean);
    let std = var.sqrt().max(1e-5);

    // Normalize
    image_array.mapv_inplace(|x| (x - mean) / std);

    Ok(image_array)
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    println!("Please enter the path to your digit image (should be a clear image of a handwritten digit):");

    let mut input = String::new();
    std::io::stdin().read_line(&mut input)?;
    let image_path = input.trim();

    // Load and preprocess the image
    match load_and_preprocess_image(image_path) {
        Ok(processed_image) => {
            // Create and run CNN
            let cnn = CNN::new();
            let predictions = cnn.forward(&processed_image);

            // Print predictions
            println!("\nDigit predictions (0-9):");
            for i in 0..10 {
                println!("Digit {}: {:.4}%", i, predictions[[0, i]] * 100.0);
            }

            // Get the most likely digit
            let mut max_prob = 0.0;
            let mut predicted_digit = 0;
            for i in 0..10 {
                if predictions[[0, i]] > max_prob {
                    max_prob = predictions[[0, i]];
                    predicted_digit = i;
                }
            }

            println!(
                "\nMost likely digit: {} (confidence: {:.2}%)",
                predicted_digit,
                max_prob * 100.0
            );
        }
        Err(e) => {
            println!("Error loading image: {}", e);
        }
    }

    Ok(())
}
