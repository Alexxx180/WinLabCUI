#include "task/structure/process/sort/selection.h"

#include "task/structure/process/sort/utils/swap.h"
#include "task/structure/process/sort/utils/efficiency.h"

void SelectionSort(std::vector<short>& memory) {
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
        Permutation();
    }
}
