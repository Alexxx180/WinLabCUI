#include "task/structure/input/array/array.h"

#include "task/structure/input/array/annotation/input.h"
#include "task/structure/input/array/choice/input.h"
#include "task/structure/input/array/choice/sort.h"
#include "task/structure/output/sort/common.h"
#include "task/structure/output/sort/header.h"
#include "task/structure/output/sort/output/output.h"
#include "task/structure/output/sort/output/restore.h"
#include "task/structure/output/sort/output/clear.h"
#include "screen/matrix/tools.h"

void StartArraySort() {
    SortCommon();
    InputDimension();
    InputChoice();
    SortChoice();
    ClearStatus();
    SelectLayer(FLOATING);
    SortHeader();
    SortOutput();
    SelectLayer(SCREEN);
    RestoreOutput();
}
