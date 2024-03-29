#include "task/structure/input/array/array.h"

#include "task/structure/input/array/choice/sort.h"
#include "task/structure/output/sort/common.h"
#include "task/structure/output/sort/header.h"
#include "task/structure/output/sort/output/output.h"

void StartArraySort() {
    SortCommon();
    SortChoice();
    SortHeader();
    SortOutput();
}
