#include "task/structure/process/sort/hoar/recursive.h"

#include "task/structure/process/sort/swap.h"

void QuickSortRecursive(std::vector<short>& memory, int first, int last) {
    int middle = memory[(first + last) / 2];
    int i = first, j = last;

    while (Comparison(memory[i] < middle)) i++;
    while (Comparison(memory[j] > middle)) j--;

    for (;i <= j; i++, j--) {
        while (Comparison(memory[i] < middle)) i++;
        while (Comparison(memory[j] > middle)) j--;
 
        SwapMemory(memory, i, j);
    }
 
    if (i < last)
        QuickSortRecursive(memory, i, last);

    if (first < j)
        QuickSortRecursive(memory, first, j);
} 

void HoarRecursive(std::vector<short>& memory) {
    QuickSortRecursive(memory, 0, memory.size() - 1);
}
