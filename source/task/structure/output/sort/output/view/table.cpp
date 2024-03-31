#include "task/structure/output/sort/output/view/table.h"

#include "screen/controls/layout/grid/datagrid/datagrid.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/lifetime/internal.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void SortTable(Page* records) {
    DataGrid model;
    model.table.SetRecords(records);

    out->Target(FOOT);
    model.OutputControls();

    out->Target(MAIN);
    model.Draw();

    char (DataGrid::*query)() = &DataGrid::Query;
    Await(&model, query, ESC);
}
