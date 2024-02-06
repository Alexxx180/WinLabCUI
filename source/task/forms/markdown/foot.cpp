#include "task/forms/markdown/foot.h"

#include <vector>

#include "screen/art/controls/grid.h"
#include "screen/matrix/booker.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"
#include "task/forms/markdown/foot/status.h"

void Form(Range* form, std::vector<std::vector<Point>> markdown) {
    Grid borders(form);
    Booker content(markdown);
    Pen::ink().Append(borders, content);
}

void FootMarkdown(Range* status, short y) {
    Markdown screens;

    screens.




    status->P1.Y += status->P2.Y + 1;
    status->P2.Y = status->P1.Y + 3;

    Point p1 = status->P1, p2 = status->P2;

    std::vector<Point> alert, table;
    alert = StatusAlert(p1.X, p2);
    table = StatusTable(p1, p2.X);

    std::vector<std::vector<Point>> messages = { alert, table };

    Form(&status->SwapXY(), messages);
}
