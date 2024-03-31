#include "screen/controls/layout/panel.h"

#include "common/types.h"
#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

void Panel :: Vertice(Point* cursor, wchar_t symbol) {
    MoveCursor(cursor);
    Draw(symbol);
}

void Panel :: DrawAngles() {
    Point anchor = BottomAnchor();
    Point cursor = TopAnchor();
    byte basis = cursor.Y;

    Angles top = TopAngles(), bottom = BottomAngles();
    Vertice(&cursor, top.left);

    cursor.Y = anchor.Y;
    Vertice(&cursor, bottom.left);

    cursor.X = anchor.X;
    Vertice(&cursor, bottom.right);

    cursor.Y = basis;
    Vertice(&cursor, top.right);
}
