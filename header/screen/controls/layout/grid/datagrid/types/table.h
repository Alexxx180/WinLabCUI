#ifndef SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_TABLE
#define SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_TABLE

#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "screen/controls/layout/grid/datagrid/types/scroll.h"

class Table {
    private:
        Page m_lines, m_records;

    public:
        Scroll Pages;
        bool End, Over;

        void Update();
        void Scroll();
        void SetRecords(Page* records);
        Page* GetLines();
        void SetLines(Page* lines);
        void Length();
        void HomePage();
        void EndPage();
        void Down();
        void Up();
};

#endif
