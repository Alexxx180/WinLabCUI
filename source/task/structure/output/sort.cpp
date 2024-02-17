#include "task/structure/output/sort.h"

#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "screen/matrix/pen.h"

void OutputArraySort() {
    unsigned char lines;

    Pen::ink().array->Rows.Set(0.5f);
    Pen::ink().array->Columns.Set(0.22f);
    Pen::ink().array.Show();

    lines = Pen::ink().back->Columns.Rib(1);
    
    Page records = { original.size(), lines };
    model.table.SetRecords(records);

    Pen::ink().Target(FOOT);
    model.OutputControls();

    Pen::ink().Target(MAIN);
    model.PagesPrint();

    Await(model.Query, ESC);

    Pen::ink().Redraw();
    Pen::ink().Target(FOOT);
    Pen::ink().Quote("status_menu_navigation");
    Pen::ink().Target(MENU);
}
