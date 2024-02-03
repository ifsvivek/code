/* Develop a program using pointers to compute the sum, mean and standard
deviation of all elements stored in an array of N real numbers.*/

#include <math.h>
#include <stdio.h>

void computeStatistics(const float *arr, int size, float *sum, float *mean,
                       float *stdDev) {
  *sum = *mean = *stdDev = 0.0;
  for (int i = 0; i < size; i++) {
    *sum += arr[i];
  }
  *mean = *sum / size;
  for (int i = 0; i < size; i++) {
    float deviation = arr[i] - *mean;
    *stdDev += deviation * deviation;
  }
  *stdDev = sqrt(*stdDev / size);
}
int main() {
  int N;
  float arr[N], sum, mean, stdDev;

  printf("Enter the number of elements: ");
  scanf("%d", &N);
  printf("Enter the elements:\n");
  for (int i = 0; i < N; i++) {
    scanf("%f", &arr[i]);
  }
  computeStatistics(arr, N, &sum, &mean, &stdDev);
  printf("Sum: %.2f\n", sum);
  printf("Mean: %.2f\n", mean);
  printf("Standard Deviation: %.2f\n", stdDev);
  return 0;
}