#include "task/markdown/foot.h"

#include "windows.h"

#include <vector>

#include "screen/art/controls/grid.h"
#include "output/booker.h"
#include "common/types.h"
#include "output/format/pen.h"

void FootMarkdown(Range* content) {
    Range status = *content;

    status.P1.Y = content->P2.Y + 1;
    status.P2.Y = status.P1.Y + 3;

    short x1 = status.P1.X, y1 = status.P1.Y + 1;
    short x2 = status.P2.X, y2 = status.P2.Y - 1;
    short margin = 3;

    std::vector<COORD> alert = {
        { x1 + margin, y2 },
        { x2 - margin, y2 }
    };
    std::vector<COORD> controls = {
        { x1 + margin, y1 },
        { x2 * 1 / 3 + margin, y1 },
        { x2 * 2 / 3 + margin, y1 }
    };

    std::vector<std::vector<COORD>> messages = { alert, controls };

    Grid foot(&status.SwapXY());
    Booker footer(messages);

    Pen::ink().Append(foot, footer);
}
