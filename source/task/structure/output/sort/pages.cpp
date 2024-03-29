#include "task/structure/output/sort/pages.h"

#include "screen/controls/grid/datagrid/types/page.h"
#include "screen/controls/grid/datagrid.h"
#include "screen/matrix/tools.h"

DataGrid model;
std::vector<short> original, sorted;

void OutputArrayRow(std::vector<short>& array, Table* table) {
    const wchar_t* numbers = L"%4i";
    uint index;
    short item;

    while (table->Over && table->End) {
        index = table->GetLines()->Absolute;
        item = array.at(index);

        pen->FText(numbers, item);
        table->Scroll();
    }
}

void OutputArray(Table* table) {
    Page backup = *(table->GetLines());

    out->Line(0);
    OutputArrayRow(original, table);

    table->SetLines(&backup);

    out->Line(1);
    OutputArrayRow(sorted, table);
}
