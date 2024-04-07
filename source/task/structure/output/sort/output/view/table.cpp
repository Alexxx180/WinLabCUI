#include "task/structure/output/sort/output/view/table.h"

#include "screen/controls/layout/grid/datagrid/datagrid.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/lifetime/internal.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"
#include "task/structure/output/sort/pages.h"

void SortTable(Page* records) {
    DataGrid model;
    model.table.SetRecords(records);

    model.SetView(&DrawArray);

    out->Target(FOOT);
    out->Line(1)->Page(0)->Size(1)->Span(3);
    out->Move()->Clear()->Move()->Span(1);
    model.OutputControls();

    out->Target(MAIN)->Page(1)->Line(0)->Move();
    model.Draw();

    char (DataGrid::*query)() = &DataGrid::Query;
    Await(&model, query, ESC);
}
