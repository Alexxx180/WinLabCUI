#include "task/forms/markdown/foot.h"

#include <vector>

#include "screen/art/controls/grid.h"
#include "screen/matrix/booker.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

void FootMarkdown(Range* status, short y) {
    status->P1.Y = y + 1;
    status->P2.Y = status.P1.Y + 3;

    short x1 = status->P1.X, y1 = status->P1.Y + 1;
    short x2 = status->P2.X, y2 = status->P2.Y - 1;
    short margin = 3;

    std::vector<Point> alert = {
        { x1 + margin, y2 },
        { x2 - margin, y2 }
    };
    std::vector<Point> controls = {
        { x1 + margin, y1 },
        { x2 * 1 / 3 + margin, y1 },
        { x2 * 2 / 3 + margin, y1 }
    };

    std::vector<std::vector<Point>> messages = { alert, controls };

    Grid foot(&status->SwapXY());
    Booker footer(messages);

    Pen::ink().Append(foot, footer);
}
