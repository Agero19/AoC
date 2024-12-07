#include <stdlib.h>
#include <stdio.h>


#define MAX_NUMBERS 1000

// UTILITY FUNCTIONS

//read and store input in separeate lists
extern void read_and_store_input(const char *filename, int *list1, int *list2, size_t *count);

// OCCURENCE 

// Runs through the given list and returns number of occurences of element
extern int nb_occur(int *list, size_t count, int value);

