input_file = "txt\\input.txt"  # Path to the input text file
output_file = "urls.txt"  # Path to the output text file

with open(input_file, "r") as f_in, open(output_file, "w") as f_out:
    for line in f_in:
        url = line.split()[0]  # Extract the URL from each line
        f_out.write(url + "\n")  # Write the URL to the output file

print("URLs extracted and written to", output_file)
