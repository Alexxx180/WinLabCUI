#include "task/forms/markdown/main.h"

#include <vector>

#include "screen/interaction.h"
#include "screen/art/controls/grid.h"
#include "screen/matrix/booker.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

void MainMarkdown(Range* content) {
    short x1 = content->P1.X, x2 = content->P2.X;
    short y = content->P1.Y + 3, margin = 3;

    std::vector<Point> input = {
        { x1 + margin, y },
        { x2 / 2 - MAX_BUFFER, y },
        { x2 / 2, y },
        { x2 / 2 + margin, y },
        { x2 - MAX_BUFFER - margin, y },
        { x2 - margin, y }
    };

    y = content->P1.Y + 1;

    short y2 = content->P2.Y - margin - 1;
    short array_y = y2 - 1;

    std::vector<Point> table = {
        { x1 + margin + 2, array_y },
        { x2 * 2 / 6, array_y },
        { x2 - margin - 1, array_y }
    };

    std::vector<std::vector<Point>> contents = { input, table };

    Grid main(&content->SwapXY());
    Booker body(contents);

    Range bar_size = {
        { x1 + margin, y2 },
        { x2 - x1 - margin, 2 }
    };

    Range output_placement = {
        { x1 + margin, array_y - 1 },
        { x2 - x1 - margin, y2 + 3 }
    };

    Grid array_output(output_placement);

    Frame bar_edges = {
        { 95, 46, 8254 },
        { 124, 39, 124 },
        { 32, 32 }, { 32, 32 }, 32
    };

    Pen::ink().array = array_output;

    Pen::ink().status.SetSize(&bar_size)->SetSymbols(&bar_edges);
    Pen::ink().status.Orientation(false);

    Pen::ink().Append(main, body);
}
