#include "task/structure/output/sort.h"

#include "screen/art/types/layers.h"
#include "screen/art/controls/data/types/page.h"
#include "screen/art/controls/data/datagrid.h"
#include "screen/interaction.h"
#include "screen/matrix/pen.h"
#include "task/structure/output/sort/pages.h"

void OutputArraySort() {
    unsigned char lines;

    DataGrid model;

    Pen::ink().array.Rows.Split(0.5f);
    Pen::ink().array.Columns.Split(0.22f);
    Pen::ink().array.Show();

    lines = Pen::ink().back->Columns.Rib(1);
    
    Page records;
    records.Relative = lines;
    records.Absolute = original.size();

    model.table.SetRecords(&records);

    Pen::ink().Target(FOOT);
    model.OutputControls();

    Pen::ink().Target(MAIN);
    model.PagesPrint();

    char (DataGrid::*query)() = &DataGrid::Query;
    Await(&model, query, ESC);

    Pen::ink().Redraw();
    Pen::ink().Target(FOOT);
    Pen::ink().Quote("status_menu_navigation");
    Pen::ink().Target(MENU);
}
