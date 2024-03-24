#include "task/structure/output/sort.h"

#include "screen/types/layers.h"
#include "screen/controls/data/grid/datagrid/types/page.h"
#include "screen/controls/data/grid/datagrid/datagrid.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/pen.h"
#include "task/structure/output/sort/pages.h"

void OutputArraySort() {
    byte lines;
    DataGrid model;

    SelectLayer(FLOATING);
    layer->Target(MAIN);

    back->Rows.Split(0.5f);
    back->Columns.Split(0.22f);
    back->Show();

    lines = back->Columns.Rib(1);
    
    Page records;
    records.Relative = lines;
    records.Absolute = original.size();

    model.table.SetRecords(&records);

    layer->Target(FOOT);
    model.OutputControls();

    layer->Target(MAIN);
    model.PagesPrint();

    char (DataGrid::*query)() = &DataGrid::Query;
    Await(&model, query, ESC);

    SelectLayer(SCREEN);

    layer->Redraw();
    layer->Target(FOOT);
    pen->Clip("status_menu_navigation");
    layer->Target(MENU);
}
