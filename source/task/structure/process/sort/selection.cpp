#include <vector>

#include "task/structure/process/sort/swap.h"

void SelectionSort(std::vector<short>& memory) {
    int i, j, size = memory.size();
    bool smaller;

    for (i = 0; i < size - 1; i++) {
        int minimal = i;

    	for (j = i + 1; j < size; j++) {

            smaller = memory[j] < memory[minimal];

	    	if (Comparison(smaller)) minimal = j;

    	}

        SwapMemory(memory, i, minimal);
    }
}
