#include "task/forms/markdown/main/table.h"

#include "common/types.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"
#include "screen/drawing/types/constructs/outlines/angles.h"
#include "screen/drawing/types/constructs/corners.h"
#include "screen/drawing/characters.h"

Corners DefaultBar() {
    Angles blank = { SPACE, SPACE };
    return {
        { UNDERSCORE, QUOTE1 },
        { PIPE, DOT },
        { PIPE, PIPE },
        { UNDERSCORE, OVERSCORE },
        blank, blank
    };
}

void MainProgressBar(Range* content) {
    byte margin = 3;

    Range size = *content;

    size.P2.X -= size.P1.X - margin;
    size.P1.X += margin;
    size.P1.Y = size.P2.Y - margin - 1;
    size.P2.Y = 2;

    Corners edges = DefaultBar();

    status.SetSize(&size);
    Pen::ink().status.SetSymbols(&edges);
    Pen::ink().status.Orientation(false);
}
