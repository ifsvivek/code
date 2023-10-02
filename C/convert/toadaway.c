#include <stdio.h>
#include <string.h>

int main() {
  FILE *input_file = fopen("in.txt", "r"); // Replace with your input file name
  FILE *output_file = fopen("output.txt", "a"); // Replace with your output file name

  if (input_file == NULL || output_file == NULL) {
    perror("Error opening files");
    return 1;
  }

  char line[256]; // Adjust the buffer size as needed
  while (fgets(line, sizeof(line), input_file) != NULL) {
    char *delimiter = "||";
    char hostname[256]; // Adjust the buffer size as needed

    // Copy the line to a new buffer so that we can modify it.
    strcpy(hostname, line);

    // Get the first hostname.
    char *hostname_ptr = strtok(hostname, delimiter);

    // If there is a second hostname, replace it with the first hostname.
    if (hostname_ptr != NULL) {
      hostname_ptr = strtok(NULL, "^");
      if (hostname_ptr != NULL) {
        strcpy(hostname, hostname_ptr);
      }
    }

    // Write the hostname to the output file without the delimiter.
    fprintf(output_file, "0.0.0.0 %s", hostname);
  }

  fclose(input_file);
  fclose(output_file);
  return 0;
}
