#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // Nécessaire pour getpid()
#include "sorting_algorithms.h"
#include <sys/time.h>

char* generate_random_string(int size) {
    static int random_seed_initialized = 0;
    if (!random_seed_initialized) {
        srand(getpid());  // Utiliser le PID comme graine pour srand()
        random_seed_initialized = 1;
    }

    char *str = malloc(size + 1);
    if (str == NULL) {
        printf("Échec de l'allocation mémoire\n");
        return NULL;
    }

    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?! ";
    int charset_size = sizeof(charset) - 1;

    for (int i = 0; i < size; i++) {
        int key = rand() % charset_size;
        str[i] = charset[key];
    }
    str[size] = '\0';

    return str;
}

double get_time() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + t.tv_usec / 1000000.0;
}

void test_sort_performance(void (*sort_func)(char *, int, int), const char *name, char *str, int size) {
    char *copy = strdup(str); // Dupliquer la chaîne pour chaque test
    double start = get_time();
    sort_func(copy, 0, size - 1); // Assume que toutes les fonctions utilisent (str, low, high)
    double end = get_time();
    free(copy); // Libérer la copie

    double time_spent = end - start;
    printf("%s took %f seconds.\n", name, time_spent);
}



int main() {
    int size = 100000;
    char *random_string = generate_random_string(size);
    if (random_string == NULL) {
        return 1;  // Retourne une erreur si la chaîne n'a pas pu être générée
    }

    printf("Testing sorting algorithms with string size of %d characters...\n", size);
    test_sort_performance(bubble_sort, "Bubble Sort", random_string, size);
    test_sort_performance(insertion_sort, "Insertion Sort", random_string, size);
    test_sort_performance(quick_sort, "Quick Sort", random_string, size);
    test_sort_performance(merge_sort, "Merge Sort", random_string, size);

    free(random_string);  // Libérer la mémoire allouée
    return 0;
}
