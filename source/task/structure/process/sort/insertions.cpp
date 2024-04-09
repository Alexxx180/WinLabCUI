#include "task/structure/process/sort/insertions.h"

#include "task/structure/process/sort/utils/efficiency.h"

void InsertionsSort(std::vector<short>& memory) {
    ResetStats();

    short i, j, size;
    short floater;

    size = memory.size();

    for (i = 0; Comparison(i < size); i++) {
        floater = memory[i];
        j = i - 1;

        while (Comparison(j >= 0 && memory[j] > floater)) {
            memory[j + 1] = memory[j];
            j--;
            permutations++;
        }

        memory[j + 1] = floater;
    }
}
