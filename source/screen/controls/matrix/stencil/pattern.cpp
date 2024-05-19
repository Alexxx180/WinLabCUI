#include "screen/controls/matrix/stencil/pattern.h"

#include "screen/drawing/characters.h"
#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"
#include "common/types.h"

void Pattern :: Clear(Point* cursor, short width) {
    MoveCursor(cursor);
    Clean(width);
}

void Pattern :: Decoration(Point* cursor, short width) {
    byte x = cursor->X;
    while (--width > 0) {
        MoveCursor(cursor);
        Draw(OVERSCORE);
        cursor->X++;
    }
    cursor->X = x;
}

void Pattern :: Pipe(Point* cursor) {
    MoveCursor(cursor);
    Draw(PIPE);
}
