#ifndef SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_SCROLL
#define SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_SCROLL

#include "common/types.h"

struct Scroll {
    const byte Top = 1;

    int Current, Bottom;

    void Home();
    void End();
    void Length();
    bool Down();
    bool Up();
};

#endif
