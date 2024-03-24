#include "task/forms/markdown/main/table.h"

#include "common/types.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"
#include "screen/drawing/types/constructs/outlines/angles.h"
#include "screen/drawing/types/constructs/corners.h"

void MainProgressBar(Range* content) {
    byte margin = 3;

    Range size = *content;

    size.P2.X -= size.P1.X - margin;
    size.P1.X += margin;
    size.P1.Y = size.P2.Y - margin - 1;
    size.P2.Y = 2;

    wchar_t pipe = 448, underscore = 818;
    Angles blank = { 32, 32 };

    Corners edges = {
        { underscore, 39 }, { pipe, 46 }, { pipe, pipe },
        { underscore, 8254 }, blank, blank
    };

    Pen::ink().status.SetSize(&size);
    Pen::ink().status.SetSymbols(&edges);
    Pen::ink().status.Orientation(false);
}
