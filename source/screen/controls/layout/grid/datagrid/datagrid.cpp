#include "screen/controls/layout/grid/datagrid/datagrid.h"

#include "common/codes.h"
#include "task/forms/defaults/debug.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/groups/table.h"

void DataGrid :: SetView(void (*update)(Table *grid)) {
    m_update = update;
}

void DataGrid :: OutputControls() {
    out->Form(1)->Page(0)->Size(1);
    out->Line(0);
    table_input.Print(FOOT);
}

void DataGrid :: Draw() {
    m_update(&table);

    out->Target(FOOT)->Move();
    out->Clear()->Move();

    if (page_character_results)
        table.Length();
    else {
        out->Clip("status_pages");
        table.Pages.Length();
    }

    out->Target(MAIN);
}

void DataGrid :: First() { table.HomePage(); }

void DataGrid :: Last() { table.EndPage(); }

void DataGrid :: Climb() { table.Up(); }

void DataGrid :: Slide() { table.Down(); }

void DataGrid :: Next() {}

void DataGrid :: Previous() {}

char DataGrid :: Action() { return UNDEFINED; }

char DataGrid :: Input() { return Select(table_input.controls); }

char DataGrid :: Query() {
    char code = Navigation::Query();
    Draw();
    return code;
}
