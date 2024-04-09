#ifndef TASK_STRUCTURE_PROCESS_SORT_INSERTIONS
#define TASK_STRUCTURE_PROCESS_SORT_INSERTIONS

#include <vector>

#include "task/structure/process/sort/utils/efficiency.h"

template<typename TYPE>
void InsertionsSort(std::vector<TYPE>& memory) {
    ResetStats();

    short i, j, size;
    TYPE floater;

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

#endif
