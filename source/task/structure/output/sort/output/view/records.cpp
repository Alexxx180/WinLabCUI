#include "task/structure/output/sort/output/view/records.h"

#include "screen/controls/data/grid/datagrid/types/page.h"
#include "screen/matrix/tools.h"

Page SortRecords() {
    back->Rows.Split(0.5f);
    back->Columns.Split(0.22f);
    back->Show();

    byte lines = back->Columns.Rib(1);

    Page records;
    records.Relative = lines;
    records.Absolute = original.size();
    return records;
}
