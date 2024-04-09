#include "task/structure/process/sort/insertions.h"

#include "task/structure/process/sort/utils/efficiency.h"

void InsertionsSort(std::vector<short>& memory) {
    ResetStats();

    short i, j, floater, size;

    size = memory.size();

    for (i = 1; Comparison(i < size); i++) {
        floater = memory[i];
        j = i;

        while (Comparison(j >= 0 && memory[j] < floater)) {
            memory[j + 1] = memory[j];
            memory[j--] = floater;
            Permutation();
        }
    }
}
