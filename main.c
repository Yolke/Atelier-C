#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_string(char *str, int size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?! ";
    int charset_size = sizeof(charset) - 1;  // -1 to exclude the null terminator

    for (int i = 0; i < size; i++) {
        int key = rand() % charset_size;
        str[i] = charset[key];
    }
    str[size] = '\0'; // Terminate the string
}

int main() {
    srand(time(NULL)); // Initialize random number generator

    // Generate a random size between 10 and 10000
    int size = rand() % (10000 - 10 + 1) + 10;

    char *random_string = malloc(size + 1); // +1 for the null terminator
    if (random_string == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    generate_random_string(random_string, size);
    printf("Random String of size %d: %s\n", size, random_string);

    free(random_string); // Free the allocated memory
    return 0;
}
