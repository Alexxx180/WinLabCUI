#include "task/forms/markdown/menu.h"

#include <vector>

#include "screen/art/controls/grid.h"
#include "screen/matrix/booker.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

void MenuMarkdown(Range* menu, short y2) {
    menu.P1.Y = y2 + 1;
    menu.P2.Y = menu.P1.Y + 3;

    short x = menu.P2.X, y = menu.P1.Y + 1;
    short margin = 3;

    std::vector<Point> controls = {
        { menu.P1.X + margin, y },
        { x * 1 / 3 + margin, y },
        { x - margin, y }
    };

    std::vector<std::vector<Point>> items = { controls };

    Grid panel(&status.SwapXY());
    Booker options(items);

    Pen::ink().Append(panel, options);
}
