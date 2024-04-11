#ifndef SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_TABLE
#define SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_TABLE

#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "screen/controls/layout/grid/datagrid/types/scroll.h"

class Table {
    private:
        bool m_end = false;
        uint m_record = 0;
        Scroll m_pages;

        void Update(uint next);

    public:
        const uint& Record = m_record;
        const bool& IsEnd = m_end;
        const bool& IsTop = m_pages.IsTop;
        const bool& IsBottom = m_pages.IsBottom;

        void Anchor();
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
