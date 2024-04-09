#include "task/structure/process/sort/utils/swap.h"

void SwapMemory(std::vector<short>& memory, int p1, int p2) {
    short placeholder = memory[p1];
    memory[p1] = memory[p2];
    memory[p2] = placeholder;
}
