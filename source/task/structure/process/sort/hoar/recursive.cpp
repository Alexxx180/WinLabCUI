#include "task/structure/process/sort/hoar/recursive.h"

void QuickSortRecursive(std::vector<short>& memory, HoarMilestone& stone) {
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
