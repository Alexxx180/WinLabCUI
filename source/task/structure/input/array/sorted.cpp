#include "task/structure/input/array/sorted.h"

#include <vector>
#include <cstdlib>

#include "common/texts/common.h"
#include "input/boundary.h"
#include "task/structure/input/sorting/parameters.h"
#include "task/structure/markdown/debug.h"
#include "task/structure/menu/array.h"
#include "task/structure/input/array/original.h"
#include "task/structure/process/sort/insertions.h"
#include "task/structure/process/sort/selection.h"
#include "task/structure/process/sort/hoar/iterative.h"
#include "task/structure/process/sort/hoar/recursive.h"
#include "task/structure/output/sort/common.h"
#include "task/structure/output/sort.h"

void (*array_sort)(std::vector<short>&)[4] = {
    HoarRecursive, QuickSortIterative,
    InsertionsSort, SelectionSort
};

void StartArraySort() {
    OutputCommonHeader();

    Boundary<short> limits(1, 20);
    numeric->Bounds(&limits);

    short size = numeric->result;

    original = ArrayInputLoop(size);
    sorted = original;

    short option = array_menu[0][1].values.SelectedIndex();

    array_sort[option](sorted);

    OutputArraySortHead();
    OutputArraySort();
}
