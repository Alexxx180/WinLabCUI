#include "task/structure/output/sort.h"

#include <vector>

#include "screen/art/controls/data/types/page.h"
#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "screen/matrix/pen.h"

DataGrid model;
std::vector<short> original, sorted;

void OutputArrayRow(std::vector<short>& array, Table* table) {
    const wchar_t* numbers = L"%4i";
    unsigned int index;
    short item;   

    while (table->Over && table->End) {
        index = table->GetLines()->Absolute;
        item = array.at(index);

        Pen::ink().FText(numbers, item);
        table->Scroll();
    }   
}

void OutputArray(Table* table) {
    Page backup = *(table->GetLines());

    Pen::ink().screen->Line(0);
    OutputArrayRow(original, table);

    table.SetLines(backup);

    Pen::ink().screen->Line(1);
    OutputArrayRow(sorted, table);
}


void OutputArraySort() {
    Pen::ink().array->Rows.Set(0.5f);
    Pen::ink().array->Columns.Set(0.22f);
    Pen::ink().Show()->screen->Span(1);

    unsigned char lines = Pen::ink().back->Columns.Rib(1);
    
    Page records = { original.size(), lines };
    model.table.SetRecords(records);

    Pen::ink().Target(FOOT);
    model.OutputControls();

    Pen::ink().Target(MAIN);
    model.PagesPrint();

    Await(model.Query, ESC);
    Pen::ink().Redraw();
    Pen::ink().Target(FOOT)->Quote("status_menu_navigation");
    Pen::ink().Target(MENU);
}

