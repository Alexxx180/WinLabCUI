#ifndef SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_PAGE
#define SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_PAGE

#include "common/types.h"

class Page {
    private:
        const byte Top = 0;

    public:
        byte Relative;
        uint Absolute;

        void Set(Page* page);
        void Iterate();
        void Home();
        void End(uint basis);
        void Down(uint wall, byte lines);
        void Up(byte lines);
        int Split();
};

#endif
