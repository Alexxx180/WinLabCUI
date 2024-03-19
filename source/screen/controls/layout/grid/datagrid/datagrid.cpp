#ifndef SCREEN_ART_CONTROLS_DATA_DATAGRID
#define SCREEN_ART_CONTROLS_DATA_DATAGRID

#include "screen/matrix/pen.h"
#include "screen/drawing/types/layers.h"
#include "screen/interaction/controller/groups/table.h"

void DataGrid :: SetView(void (*update)(Table *grid)) {
    m_update = update;
}

void DataGrid :: OutputControls() {
    Pen::ink().screen->Span(0)->Form(1);
    Pen::ink().screen->Page(0)->Size(1)->Line(0);
    Pen::ink().Quote("status_exit_esc")->screen->Page(1);
    Pen::ink().Quote("status_page_home")->screen->Page(2);
    Pen::ink().Quote("status_page_up")->screen->Line();
    Pen::ink().Quote("status_page_down")->screen->Page(1);
    Pen::ink().Quote("status_page_end")->screen->Page(0);
    Pen::ink().screen->Span(1);
}

void DataGrid :: PagesPrint() {
    m_update(&table);

    Pen::ink().Target(FOOT);
    Pen::ink().screen->Move()->Clear()->Move();

    if (page_character_results)
        table.Length();
    else {
        Pen::ink().Quote("status_pages");
        table.Pages.Length();
    }

    Pen::ink().Target(MAIN);
}

void DataGrid :: First() { table.HomePage(); }

void DataGrid :: Last() { table.EndPage(); }

void DataGrid :: Climb() { table.Up(); }

void DataGrid :: Slide() { table.Down(); }

char DataGrid :: Input() { return Select(table_controls); }

char DataGrid :: Query() {
    char code = Navigation::Query();
    PagesPrint();
    return code;
}
