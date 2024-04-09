#ifndef TASK_STRUCTURE_PROCESS_SORT_UTILS_SWAP
#define TASK_STRUCTURE_PROCESS_SORT_UTILS_SWAP

#include <vector>

template<typename TYPE>
void SwapMemory(std::vector<TYPE>& memory, int p1, int p2) {
    TYPE placeholder = memory[p1];
    memory[p1] = memory[p2];
    memory[p2] = placeholder;
}

#endif
