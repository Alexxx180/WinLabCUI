#include "screen/art/drawing/outlines.h"

#include "screen/art/drawing.h"
#include "screen/matrix/types/point.h"

void Field(Point space, short size) {
    space.X--;
    MoveCursor(&space);
    Draw(L'|');
    space.Y++;

    while (--size >= 0) {
        space.X++;
        MoveCursor(&space);
        Draw(L'‾'); 
    }
}
