#include "task/structure/input/array/sorted.h"

#include <vector>
#include <cstdlib>

#include "common/texts/common.h"
#include "input/boundary.h"
#include "task/forms/debug.h"
#include "task/structure/input/menu/array.h"
#include "task/structure/input/array/original.h"
#include "task/structure/process/sort/insertions.h"
#include "task/structure/process/sort/selection.h"
#include "task/structure/process/sort/hoar/iterative.h"
#include "task/structure/process/sort/hoar/recursive.h"
#include "task/structure/output/sort/common.h"
#include "task/structure/output/sort/pages.h"
#include "task/structure/output/sort.h"

void (*array_sort[4])(std::vector<short>&) = {
    HoarRecursive, QuickSortIterative,
    InsertionsSort, SelectionSort
};

void StartArraySort() {
    OutputCommonHeader();

    Boundary<char> limits(1, 20);
    numeric->Bounds(&limits);

    char size = numeric->result;
    original = ArrayInputLoop(size);
    sorted = original;

    short option = array_menu.at(0).at(1).Choice();
    array_sort[option](sorted);

    OutputArraySortHead();
    OutputArraySort();
}
