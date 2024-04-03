#include "task/structure/input/array/choice/sort.h"

#include "task/structure/shared/arrays.h"
#include "task/structure/input/array/menu.h"
#include "task/structure/process/sort/insertions.h"
#include "task/structure/process/sort/selection.h"
#include "task/structure/process/sort/hoar/iterative.h"
#include "task/structure/process/sort/hoar/recursive.h"

void SortChoice() {
    char sort = SortOption();

    sort_type array[4] = {
        HoarRecursive,
        QuickSortIterative,
        InsertionsSort,
        SelectionSort
    };

    array[sort](sorted);
}
