#include "task/structure/output/sort/pages.h"

#include <vector>

#include "screen/art/controls/data/types/page.h"
#include "screen/art/controls/data/types/table.h"
#include "screen/art/controls/data/datagrid.h"
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

    table->SetLines(&backup);

    Pen::ink().screen->Line(1);
    OutputArrayRow(sorted, table);
}
