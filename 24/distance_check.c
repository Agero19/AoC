#include "distance_check.h"

long long count_total_distance(int *arr1, int *arr2, size_t count) {
    long long distance = 0;
    for (size_t i = 0; i < count; i++) {
        distance += abs(arr1[i] - arr2[i]);
    }
    return distance;
}