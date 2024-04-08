#ifndef SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_SCROLL
#define SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_SCROLL

#include "screen/controls/layout/grid/datagrid/types/page.h"

class Scroll {
    private:
        const byte Top = 0, First = 1;

        bool m_isTop = true, m_isBottom = false;
        uint m_current = 0, m_records = 0, m_last = 0;
        Page m_page;

        void Reload(long value);
        void Update(long next);

    public:
        const bool& IsTop = m_isTop;
        const bool& IsBottom = m_isBottom;
        const uint& Last = m_last;
        const uint& Records = m_records;
        const Page& Enumeration = m_page;

        void Set(const Page& records);

        void Length();
        void Count();

        void Home();
        void End();
        void Down();
        void Up();
};

#endif
