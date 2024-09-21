#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* load_file_as_string(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    // Move the file pointer to the end and find the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file); // Go back to the beginning of the file

    // Allocate memory for the string (+1 for null terminator)
    char *string = (char *)malloc((file_size + 1) * sizeof(char));
    if (string == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    // Read the file contents into the string
    size_t read_size = fread(string, sizeof(char), file_size, file);
    string[read_size] = '\0';  // Null-terminate the string

    fclose(file);
    return string;
}
int main() {
    system("rm index.html");
    system("wget https://my.sport.uni-goettingen.de/fiz/");

    const char delim[] = " ";  // Delimiter is a space
    char *token;

    // Use strtok() to get the first token
    token = strtok(str, delim);

    // Walk through other tokens
    while (token != NULL) {
        printf("%s\n", token);  // Print each token
        token = strtok(NULL, delim);  // Get the next token
    }

    return 0;
}
