#include "task/structure/output/sort/output/view/table.h"

#include "screen/controls/data/grid/datagrid/datagrid.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void SortTable(Page* records) {
    DataGrid model;
    model.table.SetRecords(&records);

    layer->Target(FOOT);
    model.OutputControls();

    layer->Target(MAIN);
    model.PagesPrint();

    char (DataGrid::*query)() = &DataGrid::Query;
    Await(&model, query, ESC);
}
