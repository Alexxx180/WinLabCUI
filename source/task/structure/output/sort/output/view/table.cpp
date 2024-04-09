#include "task/structure/output/sort/output/view/table.h"

#include "screen/controls/layout/grid/datagrid/datagrid.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/lifetime/internal.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"
#include "task/structure/output/sort/pages.h"

void SortTable(const Page& records) {
    DataGrid model;
    model.table.Set(records);

    model.SetView(&DrawArray);

    out->Target(FOOT);
    out->Page(0)->Line(1)->Size(1)->Span(1);
    model.OutputControls();
    out->Page(0)->Line(1)->Move();

    out->Target(MAIN)->Page(1)->Line(0)->Move();
    model.Draw();

    char (DataGrid::*query)() = &DataGrid::Query;
    Await(&model, query, ESC);

    out->Page(0)->Line(3)->Span(3);
    out->Move()->Clear()->Line(0)->Move();

    out->Target(FOOT);
    model.ClearControls();
}
