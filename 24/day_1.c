#include <stdio.h>
#include "sorting.h"
#include "utility.h"
#include "distance_check.h"

int main() {
    const char *filename = "data/location_id.txt";  
    int list1[MAX_NUMBERS], list2[MAX_NUMBERS];
    size_t count = 0;

    //Reading and storing in separate lists
    read_and_store_input(filename, list1, list2, &count);
    
    //Sorting two arrays
    quicksort(list1, 0, count - 1);
    quicksort(list2, 0, count - 1);

    //Counting distance
    long long result = count_total_distance(list1, list2, count);
    printf("Total distance = %lld\n", result);

    return 0;
}