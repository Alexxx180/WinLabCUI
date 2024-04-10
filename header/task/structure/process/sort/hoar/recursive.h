#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_RECURSIVE
#define TASK_STRUCTURE_PROCESS_SORT_HOAR_RECURSIVE

#include <vector>

#include "task/structure/process/sort/hoar/types/milestone.h"
#include "task/structure/process/sort/utils/efficiency.h"

template<typename TYPE>
void QuickSortRecursive(std::vector<TYPE>& memory, HoarMilestone<TYPE>& stone) {
    int first = stone.Left, last = stone.Right;
    stone.Sort(memory);

    if (Comparison(stone.Left < last)) {
        stone.Right = last;
        QuickSortRecursive(memory, stone);
    }

    if (Comparison(first < stone.Right)) {
        stone.Left = first;
        QuickSortRecursive(memory, stone);
    }
}

template<typename TYPE>
void HoarRecursive(std::vector<TYPE>& memory) {
    HoarMilestone<TYPE> stone(0, memory.size() - 1);
    QuickSortRecursive(memory, stone);
}

#endif
