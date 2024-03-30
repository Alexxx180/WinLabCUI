#include "task/structure/output/sort/pages.h"

#include "screen/controls/layout/grid/datagrid/datagrid.h"
#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "screen/matrix/tools.h"

std::vector<short> original, sorted;

void DrawRow(char line, std::vector<short>& array, Table* table) {
    const wchar_t* numbers = L"%4i";
    uint index;
    short item;

    out->Line(line);

    while (table->Over && table->End) {
        index = table->GetLines()->Absolute;
        item = array.at(index);

        pen->FText(numbers, item);
        table->Scroll();
    }
}

void DrawArray(Table* table) {
    Page backup = *(table->GetLines());

    DrawRow(0, original, table);
    table->SetLines(&backup);
    DrawRow(1, sorted, table);
}
