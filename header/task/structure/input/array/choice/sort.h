#ifndef TASK_STRUCTURE_INPUT_ARRAY_CHOICE_SORT
#define TASK_STRUCTURE_INPUT_ARRAY_CHOICE_SORT

#include "task/structure/shared/arrays.h"
#include "task/structure/input/array/menu.h"
#include "task/structure/process/sort/insertions.h"
#include "task/structure/process/sort/selection.h"
#include "task/structure/process/sort/hoar/iterative.h"
#include "task/structure/process/sort/hoar/recursive.h"

template<typename TYPE>
void SortChoice(std::vector<TYPE>& sorted) {
    char sort = SortOption();
    
    void (*array[4])(std::vector<TYPE>&) = {
        InsertionsSort,
        SelectionSort,
        HoarRecursive,
        HoarIterative
    };

    array[sort](sorted);
}

#endif
