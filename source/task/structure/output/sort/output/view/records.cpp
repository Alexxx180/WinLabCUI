#include "task/structure/output/sort/output/view/records.h"

#include "task/structure/shared/arrays.h"
#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "screen/matrix/tools.h"

Page SortRecords() {
    out->ShowBack();
    Page records;
    records.Relative = 10;
    records.Absolute = original.size();
    return records;
}
