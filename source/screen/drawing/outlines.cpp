#include "screen/art/drawing/outlines.h"

#include "screen/art/drawing.h"
#include "screen/matrix/types/point.h"

void Field(Point* space, const short size) {
    Point field = *space;
    field.X--;
    MoveCursor(field);
    Draw(L'|');
    field.Y++;

    short i = size;
    while (--i >= 0) {
        field.X++;
        MoveCursor(&field);
        Draw(L'‾'); 
    }
}
