#include "screen/controls/matrix/stencil/pattern.h"

#include "screen/drawing/characters.h"
#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

void Pattern :: Clear(Point* cursor, short width) {
    MoveCursor(cursor);
    Clean(width);
}

void Pattern :: Decoration(Point* cursor, short width) {
    while (--width > 0) {
        cursor->X--;
        MoveCursor(cursor);
        Draw(OVERSCORE);
    }
}

void Pattern :: Pipe(Point* cursor) {
    MoveCursor(cursor);
    Draw(PIPE);
}
