#include "task/structure/process/sort/insertions.h"

#include <vector>

#include "task/structure/process/sort/swap.h"

void InsertionsSort(std::vector<short>& memory) {
    short i, j, floater, size;

    size = memory.size();

    for (i = 1; i < size; i++) {
        floater = memory[i];
        j = i;

        while (j >= 0 && Comparison(memory[j] < floater)) {
            memory[j + 1] = memory[j];
            memory[j--] = floater;
            Permutation();
        }
    }
}
