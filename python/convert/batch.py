import glob

def convert_and_append_to_adaway(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'a') as outfile:
        for line in infile:
            parts = line.strip().split('||')
            if len(parts) == 2:
                hostname = parts[1].strip('^')
                outfile.write(f"0.0.0.0 {hostname}\n")

# Directory containing input files with a *.txt pattern
input_directory = 'python\convert'

# Output file name
output_file = 'lol\output.txt'  # Replace with your desired output file name

# Get a list of all *.txt files in the input directory
input_files = glob.glob(input_directory + '*.txt')

# Process each input file
for input_file in input_files:
    convert_and_append_to_adaway(input_file, output_file)
