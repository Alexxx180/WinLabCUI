#ifndef SCREEN_ART_CONTROLS_DATA_DATAGRID
#define SCREEN_ART_CONTROLS_DATA_DATAGRID

#include "screen/matrix/pen.h"
#include "screen/art/types/layers.h"
#include "screen/art/controls/data/types/table.h"

static std::vector<char> table_controls = {
    ESC, HOME, END, PAGE_UP, PAGE_DOWN
};

class DataGrid {
    private:
        void (*m_update)(Table *grid) = NULL;

    public:
        Table table;

        void SetView(void (*update)(Table *grid)) {
            m_update = update;
        }

        void OutputControls() {
            Pen::ink().screen->Span(0)->Form(1);
            Pen::ink().screen->Page(0)->Size(1)->Line(0);
            Pen::ink().Quote("status_exit_esc")->screen->Page(1);
            Pen::ink().Quote("status_page_home")->screen->Page(2);
            Pen::ink().Quote("status_page_up")->screen->Line();
            Pen::ink().Quote("status_page_down")->screen->Page(1);
            Pen::ink().Quote("status_page_end")->screen->Page(0);
            Pen::ink().screen->Span(1);
        }

        void PagesPrint() {
            m_update(&table);

            Pen::ink().Target(FOOT);
            Pen::ink().screen->Move()->Clear()->Move();

            if (page_character_results)
                table.Length();
            else {
                Pen::ink().Text(caption);
                table.Pages.Length();
            }

            Pen::ink().Target(MAIN);
        }

        char Query() {
            char code = Select(table_controls);
            if (code == ESC) return code;

            switch (code) {
                case HOME: table.HomePage(); break;
                case END: table.EndPage(); break;
                case PAGE_UP: table.Up(); break;
                case PAGE_DOWN: table.Down(); break;
                default: break;
            }

            PagesPrint();
            return code;
        }
};

#endif
