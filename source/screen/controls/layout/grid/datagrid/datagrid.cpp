#include "screen/controls/layout/grid/datagrid/datagrid.h"

#include "task/forms/defaults/debug.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/groups/table.h"

void DataGrid :: SetView(void (*update)(Table *grid)) {
    m_update = update;
}

void DataGrid :: OutputControls() {
    out->Form(1)->Page(0)->Span(0);
    out->Line(0)->Size(1);
    table_input.Print(FOOT);
    out->Span(1);
}

void DataGrid :: Draw() {
    m_update(&table);

    layer->Target(FOOT);
    out->Move()->Clear()->Move();

    if (page_character_results)
        table.Length();
    else {
        pen->Clip("status_pages");
        table.Pages.Length();
    }

    layer->Target(MAIN);
}

void DataGrid :: First() { table.HomePage(); }

void DataGrid :: Last() { table.EndPage(); }

void DataGrid :: Climb() { table.Up(); }

void DataGrid :: Slide() { table.Down(); }

char DataGrid :: Input() { return Select(table_input.controls); }

char DataGrid :: Query() {
    char code = Navigation::Query();
    Draw();
    return code;
}
