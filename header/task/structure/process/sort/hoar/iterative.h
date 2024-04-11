#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_ITERATIVE
#define TASK_STRUCTURE_PROCESS_SORT_HOAR_ITERATIVE

#include <vector>

#include "task/structure/process/sort/hoar/types/iterator.h"

template<typename TYPE>
void HoarIterative(std::vector<TYPE>& memory) {
    HoarIterator iterator(memory.size());
    iterator.Sort(memory);
}

#endif
