#include "screen/controls/layout/grid/datagrid/types/page.h"

void Page :: Set(const Page& clone) {
    Relative = clone.Relative;
    Absolute = clone.Absolute;
}

int Page :: Split() {
    int start = Absolute % Relative;
    int end = Absolute / Relative;
    if (start != 0) end += 1;
    return end;
}
