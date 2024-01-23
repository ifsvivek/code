// Write a C program to copy a text file to another, read both the input file name and target file name

#include <stdio.h>

#define MAX_FILENAME_LENGTH 100
#define BUFFER_SIZE 1024

int main()
{
    char inputFile[MAX_FILENAME_LENGTH];
    char outputFile[MAX_FILENAME_LENGTH];
    FILE *sourceFile, *targetFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    printf("Enter the input file name: ");
    scanf("%s", inputFile);

    printf("Enter the target file name: ");
    scanf("%s", outputFile);

    sourceFile = fopen(inputFile, "r");
    targetFile = fopen(outputFile, "w");

    if (sourceFile == NULL || targetFile == NULL)
    {
        printf("Failed to open the files.\n");
        return 1;
    }

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, sourceFile)) > 0)
    {
        fwrite(buffer, sizeof(char), bytesRead, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);

    printf("File copied successfully.\n");

    return 0;
}