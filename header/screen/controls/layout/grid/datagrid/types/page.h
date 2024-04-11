#ifndef SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_PAGE
#define SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_TYPES_PAGE

#include "common/types.h"

struct Page {
    byte Relative = 0;
    uint Absolute = 0;

    void Set(const Page& clone);
    uint Split();
};

#endif
