#include "similarity.h"

long long calcuate_similarity(int *list1, int *list2, size_t count) {
    long long score = 0;

    for (size_t i = 0; i < count; i++) {
        score += list1[i] * nb_occur(list2, count, list1[i]);
    }

    return score;
}
