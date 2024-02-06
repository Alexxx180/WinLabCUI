#include "task/forms/markdown/main/table.h"

#include "screen/art/types/frame.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

void BarMarkdown(Range* content) {
    unsigned char margin = 3;

    Range size = *content;

    size.P2.X -= size.P1.X - margin;
    size.P1.X += margin;
    size.P1.Y = size.P2.Y - margin - 1;
    size.P2.Y = 2;

    Frame edges = {
        { 95, 46, 8254 }, { 124, 39, 124 },
        { 32, 32 }, { 32, 32 }, 32
    };

    Pen::ink().status.SetSize(&size);
    Pen::ink().status.SetSymbols(&edges);
    Pen::ink().status.Orientation(false);
}
