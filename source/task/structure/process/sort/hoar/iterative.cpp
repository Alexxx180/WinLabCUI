#include "task/structure/process/sort/hoar/iterative.h"

#include "task/structure/process/sort/hoar/types/iterator.h"

void HoarIterative(std::vector<short>& memory) {
    HoarIterator iterator(memory.size() - 1);
    iterator.Sort(memory);
}
