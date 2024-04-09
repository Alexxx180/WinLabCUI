#include "task/structure/output/sort/pages.h"

#include "common/texts/format.h"
#include "task/structure/shared/arrays.h"
#include "screen/controls/layout/grid/datagrid/datagrid.h"
#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "screen/matrix/tools.h"

void DrawRow(char line, std::vector<short>& array, Table& table) {
    short item;

    out->Line(line)->Move()->Clear()->Move();

    for (table.Anchor(); !table.IsEnd; table.Scroll()) {
        item = array.at(table.Record);
        out->FText(NO4, item);
    }
}

void DrawArray(Table& table) {
    DrawRow(0, original, table);
    DrawRow(1, sorted, table);
}
