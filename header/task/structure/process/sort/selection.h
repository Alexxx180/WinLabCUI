#ifndef TASK_STRUCTURE_PROCESS_SORT_SELECTION
#define TASK_STRUCTURE_PROCESS_SORT_SELECTION

#include <vector>

#include "task/structure/process/sort/utils/swap.h"
#include "task/structure/process/sort/utils/efficiency.h"

template<typename TYPE>
void SelectionSort(std::vector<TYPE>& memory) {
    ResetStats();

    int i, j, size = memory.size();
    bool smaller;

    for (i = 0; Comparison(i < size - 1); i++) {
        int minimal = i;

        for (j = i + 1; Comparison(j < size); j++) {

            smaller = memory[j] < memory[minimal];

            if (Comparison(smaller)) minimal = j;

        }

        SwapMemory(memory, i, minimal);
        permutations++;
    }
}

#endif
