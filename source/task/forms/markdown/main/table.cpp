#include "task/forms/markdown/main/table.h"

#include "common/types.h"
#include "screen/art/controls/grid.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

void TableGrid(Range* content) {
    byte margin = 3;

    Range placement = *content;
    placement.P2.X -= placement.P1.X - margin;
    placement.P1.X += margin;
    placement.P1.Y = placement.P2.Y - margin - 2;
    placement.P2.Y += 3;

    Grid output(&placement);
    Pen::ink().array = output;
}
