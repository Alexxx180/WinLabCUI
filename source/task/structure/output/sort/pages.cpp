#include "task/structure/output/sort/pages.h"

#include "common/texts/format.h"
#include "task/structure/shared/arrays.h"
#include "screen/controls/layout/grid/datagrid/datagrid.h"
#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "screen/matrix/tools.h"

void DrawRow(char line, std::vector<short>& array, Table* table) {
    uint index;
    short item;

    out->Line(line);

    while (table->Over && table->End) {
        index = table->GetLines()->Absolute;
        item = array.at(index);

        out->FText(NO4, item);
        table->Scroll();
    }
}

void DrawArray(Table* table) {
    Page backup = *(table->GetLines());

    DrawRow(0, original, table);
    table->SetLines(&backup);
    DrawRow(1, sorted, table);
}
