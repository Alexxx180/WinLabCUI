#include "screen/controls/matrix/stencil/pattern.h"

#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

#include "screen/matrix/types/point.h"

void Pattern :: SetCursor(Point* cursor) {
    m_cursor = cursor;
}

void Pattern :: Move() {
    MoveCursor(m_cursor);
}

void Pattern :: Clear() {
    Move();
    Clean(Diff());
}

void Pattern :: Shift(short width) {
    m_cursor.X += width;
}

void Pattern :: Decoration(char baseline, short width) {
    m_cursor.Y += baseline;

    while (--width >= 0) {
        m_cursor.X--;
        Move();
        Draw(pipe_horizontal); 
    }

    m_cursor.Y -= baseline;
    Move();
}

void Pattern :: Pipe() {
    Move();
    Draw(pipe_vertical);
}
