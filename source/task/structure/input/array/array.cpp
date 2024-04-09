#include "task/structure/input/array/array.h"

#include "task/structure/shared/painter.h"
#include "task/structure/input/array/annotation/define.h"
#include "task/structure/output/sort/common.h"
#include "task/structure/output/sort/header.h"
#include "task/structure/output/sort/output/restore.h"
#include "task/structure/output/sort/output/clear.h"
#include "task/structure/input/array/menu.h"
#include "screen/matrix/tools/layers.h"

void StartArraySort() {
    SortCommon();

    ArrayDefine(TypeOption() ? astrings : anumbers);

    ClearStatus();
    SelectLayer(FLOATING);

    SortHeader();
    painter.Output();

    SelectLayer(SCREEN);
    RestoreOutput();
}
