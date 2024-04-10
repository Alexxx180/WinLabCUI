#ifndef TASK_STRUCTURE_SHARED_PAINTER
#define TASK_STRUCTURE_SHARED_PAINTER

#include "screen/controls/layout/grid/datagrid/types/table.h"

struct SharedPainter {
    virtual void Draw(Table& table) = 0;
    virtual void Output() = 0;
};

#endif
