#include "utility.h"


void read_and_store_input(const char *filename, int *list1, int *list2, size_t *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int num1, num2;
    *count = 0;

    while (fscanf(file, "%d %d", &num1, &num2) == 2) {
        if (*count >= MAX_NUMBERS) {
            fprintf(stderr, "Error: Exceeded maximum allowed numbers.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        list1[*count] = num1;
        list2[*count] = num2;
        (*count)++;
    }

    fclose(file);
}

int nb_occur(int *list, size_t count, int value) {
    int occur = 0;

    for (size_t i = 0; i < count; i++) {
        if (list[i] == value) {
            occur += 1;
        }
    }

    return occur;
}
