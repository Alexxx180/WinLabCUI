#include "screen/controls/layout/grid/datagrid/datagrid.h"

#include "common/codes.h"
#include "task/forms/defaults/debug.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/groups/table.h"

void DataGrid :: SetView(void (*update)(Table& grid)) {
    m_update = update;
}

void DataGrid :: OutputControls() { table_input.Print(); }
void DataGrid :: ClearControls() { table_input.Clear(); }

void DataGrid :: Draw() {
    m_update(table);
    out->Target(FOOT);
    out->Move()->Clear()->Move();
    table.Progress();
    out->Target(MAIN);
}

void DataGrid :: Next() {}
void DataGrid :: Previous() {}
char DataGrid :: Action() { return UNDEFINED; }
short DataGrid :: Choice() { return UNDEFINED; }

void DataGrid :: List(bool wall, listing pages) {
    if (!wall) { 
        (table.*pages)();
        Draw();
    }
}

void DataGrid :: First() { List(table.IsTop, &Table::Home); }

void DataGrid :: Last() { List(table.IsBottom, &Table::End); }

void DataGrid :: Climb() { List(table.IsTop, &Table::Up); }

void DataGrid :: Slide() { List(table.IsBottom, &Table::Down); }

char DataGrid :: Input() { return Select(table_input.controls); }
