#include "task/markdown/main.h"

#include "windows.h"

#include <vector>

#include "screen/art/controls/grid.h"
#include "output/booker.h"
#include "screen/interaction.h"
#include "common/types.h"
#include "output/format/pen.h"

void MainMarkdown(Range* content) {
    short x1 = content->P1.X, x2 = content->P2.X;
    short y = content->P1.Y + 3, margin = 3;

    std::vector<COORD> input = {
        { x1 + margin, y },
        { x2 / 2 - MAX_BUFFER, y },
        { x2 / 2, y },
        { x2 / 2 + margin, y },
        { x2 - MAX_BUFFER - margin, y },
        { x2 - margin, y }
    };

    y = content->P1.Y + 1;

    std::vector<COORD> table = {
        { x1 + margin, y },
        { x2 * 1 / 3 - margin, y },
        { x2 * 1 / 3 + margin, y },
        { x2 * 2 / 3 - margin, y },
        { x2 * 2 / 3 + margin, y },
        { x2 - 1, y }
    };

    std::vector<std::vector<COORD>> contents = { input, table };

    Grid main(&content->SwapXY());
    Booker body(contents);

    short y2 = content->P2.Y - margin - 1;

    Range bar_size = {
        { x1 + margin, y2 },
        { x2 - x1 - margin, 2 }
    };

    Frame bar_edges = {
        { 95, 46, 8254 },
        { 124, 39, 124 },
        { 32, 32 }, { 32, 32 }, 32
    };

    Pen::ink().status.SetSize(&bar_size)->SetSymbols(&bar_edges);
    Pen::ink().status.Orientation(false);

    Pen::ink().Append(main, body);
}
