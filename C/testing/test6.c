#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_KEYWORDS 10
#define MAX_IDENTIFIER_LEN 20

const char* keywords[] = { "for", "while", "do", "int", "float", "char",
                          "double", "static", "switch", "case" };

int open_file(const char* filename, FILE** fp, const char* mode) {
    *fp = fopen(filename, mode);
    if (*fp == NULL) {
        printf("Error opening file: %s\n", filename);  // Print the filename
        perror("");
        return 1;
    }
    return 0;
}

void close_files(FILE* f1, FILE* f2, FILE* f3) {
    if (f1 != NULL) {
        fclose(f1);
    }
    if (f2 != NULL) {
        fclose(f2);
    }
    if (f3 != NULL) {
        fclose(f3);
    }
}

void process_file(FILE* input, FILE* identifier_file, FILE* specialchar_file) {
    int num_identifiers = 0, num_special_chars = 0;
    char c, identifier[MAX_IDENTIFIER_LEN + 1];

    while ((c = fgetc(input)) != EOF) {
        if (isdigit(c)) {
            // Handle numbers
            printf("%c is a number\n", c);
        } else if (isalpha(c) || c == '_') {  // Allow identifiers to start with underscore
            int i = 0;
            while (isalpha(c) || isdigit(c) || c == '_') {
                identifier[i++] = c;
                c = fgetc(input);
                if (i >= MAX_IDENTIFIER_LEN) {
                    break;
                }
            }
            identifier[i] = '\0';
            ungetc(c, input);

            // Check for keyword
            int is_keyword = 0;
            for (int j = 0; j < MAX_KEYWORDS; j++) {
                if (strcmp(identifier, keywords[j]) == 0) {
                    is_keyword = 1;
                    break;
                }
            }
            if (is_keyword) {
                printf("\n%s is a keyword\n", identifier);
            } else {
                fprintf(identifier_file, "%s\n", identifier);
                num_identifiers++;
            }
        } else if (!isspace(c)) {  // Skip whitespaces and print special characters
            fprintf(specialchar_file, "%c", c);
            num_special_chars++;
        }
    }

    printf("\nThe keywords and identifiers are:\n");
    // Print identifiers from the file
    rewind(identifier_file); // Reset file pointer to the beginning
    while (fgets(identifier, MAX_IDENTIFIER_LEN + 2, identifier_file) != NULL) {
        // Remove trailing newline from fgets output
        identifier[strcspn(identifier, "\n")] = '\0';
        printf("%s\n", identifier);
    }
    printf("\nSpecial characters are:\n");
    // Print special characters from the file
    rewind(specialchar_file);
    while ((c = fgetc(specialchar_file)) != EOF) {
        printf("%c", c);
    }
}

int main() {
    FILE* input;
    FILE* identifier_file;
    FILE* specialchar_file;

    if (open_file("input.txt", &input, "r") != 0) {
        return 1;
    }
    if (open_file("identifiers.txt", &identifier_file, "w") != 0) {
        return 1;
    }
    if (open_file("special_chars.txt", &specialchar_file, "w") != 0) {
        return 1;
    }

    process_file(input, identifier_file, specialchar_file);


    close_files(input, identifier_file, specialchar_file);

    return 0;
}