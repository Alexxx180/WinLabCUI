#include "task/structure/output/sort/output/view/records.h"

#include "task/structure/shared/arrays.h"
#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "screen/matrix/tools.h"

Page SortRecords() {
    out->ShowBack();

    byte lines = out->back.current->Columns.Rib(1);

    Page records;
    records.Relative = lines;
    records.Absolute = original.size();
    return records;
}
