#include "task/structure/input/array/choice/sort.h"

#include "common/texts/common.h"
#include "input/limiting/boundary.h"

#include "task/forms/defaults/io/input.h"

#include "task/structure/output/sort/pages.h"

#include "task/structure/input/array/common.h"
#include "task/structure/input/array/choice/input.h"

#include "task/structure/process/sort/insertions.h"
#include "task/structure/process/sort/selection.h"
#include "task/structure/process/sort/hoar/iterative.h"
#include "task/structure/process/sort/hoar/recursive.h"

sort_invokation SortSelect() {
    sort_invokation array_sort[4] = {
        HoarRecursive, QuickSortIterative, InsertionsSort, SelectionSort
    };
    return array_sort[SortOption()];
}

void SortChoice() {
    char size = numeric->result;

    Boundary<char> limits(1, 20);

    numeric->Bounds(&limits);
    original = ArrayInput(size);

    sort_invokation array_sort = SortSelect();

    sorted = original;
    array_sort(sorted);
}
