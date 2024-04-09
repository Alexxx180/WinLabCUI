#include "task/structure/process/sort/hoar/recursive.h"

#include "task/structure/process/sort/utils/efficiency.h"

void QuickSortRecursive(std::vector<short>& memory, HoarMilestone& stone) {
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

void HoarRecursive(std::vector<short>& memory) {
    HoarMilestone stone(0, memory.size() - 1);
    QuickSortRecursive(memory, stone);
}
