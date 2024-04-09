#include "task/structure/process/sort/utils/efficiency.h"

short permutations = 0, comparisons = 0;

void ResetStats() {
    permutations = 0;
    comparisons = 0;
}

void Permutation() {
    permutations++;
}

bool Comparison(bool condition) {
    comparisons++;
    return condition;
}
