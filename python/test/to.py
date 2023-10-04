def convert_and_append_to_adaway(input_file, output_file):
    with open(input_file, 'r', encoding='iso-8859-1') as infile, open(output_file, 'a') as outfile:
        for line in infile:
            parts = line.strip().split('||')
            if len(parts) == 2:
                hostname = parts[1].strip('^')
                outfile.write(f"0.0.0.0 {hostname}\n")

# Usage
input_file = 'easylist.txt'  # Replace with your input file name
output_file = 'output.txt'  # Replace with your desired output file name
convert_and_append_to_adaway(input_file, output_file)
