#include "task/structure/output/sort/output/view/records.h"

#include "task/structure/output/sort/pages.h"
#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "screen/matrix/tools.h"

Page SortRecords() {
    out->back.current->Rows.Split(0.5f);
    out->back.current->Columns.Split(0.22f);
    out->ShowBack();

    byte lines = out->back.current->Columns.Rib(1);

    Page records;
    records.Relative = lines;
    records.Absolute = original.size();
    return records;
}
