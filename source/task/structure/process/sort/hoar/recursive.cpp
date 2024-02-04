#include "task/structure/process/sort/hoar/recursive.h"

#include <vector>

#include "task/structure/process/sort/swap.h"

// First iteration: 0, n - 1

void QuickSortRecursive(std::vector<short>& memory, int first, int last) {
    int middle = memory[(first + last) / 2];
    int i = first, j = last;

    while (memory[i] < middle) i++;
    while (memory[j] > middle) j--;

    for (;i <= j; i++, j--) {
        while (memory[i] < middle) i++;
        while (memory[j] > middle) j--;
 
        SwapMemory(memory, i, j);
    }
 
    if (i < last)
        QuickSortRecursive(memory, i, last);

    if (first < j)
        QuickSortRecursive(memory, first, j);
} 
