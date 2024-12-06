#include "sorting.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

size_t partition(int arr[], size_t low, size_t high) {
    int pivot = arr[high]; // Select the last element as pivot
    size_t i = low - 1;    // Index of smaller element

    for (size_t j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than the pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place pivot in its correct position
    return i + 1;
}

// Quicksort function
void quicksort(int arr[], size_t low, size_t high) {
    if (low < high) {
        size_t pi = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        if (pi > 0) { // Ensure no underflow for `low` when subtracting 1
            quicksort(arr, low, pi - 1);
        }
        quicksort(arr, pi + 1, high);
    }
}