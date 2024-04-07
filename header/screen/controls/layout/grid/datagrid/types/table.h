#ifndef SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_TABLE
#define SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_TABLE

#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "screen/controls/layout/grid/datagrid/types/scroll.h"

class Table {
    private:
        bool m_end;
        uint m_line = 0;
        Scroll m_pages;

    public:
        const bool& End = m_end;
        const bool& IsTop = m_pages.IsTop;
        const bool& IsBottom = m_pages.IsBottom;

        void Scroll();
        void Set(const Page& records);
        void Progress();
        void Home();
        void End();
        void Down();
        void Up();
};

typedef void (Table::*listing)();

#endif
