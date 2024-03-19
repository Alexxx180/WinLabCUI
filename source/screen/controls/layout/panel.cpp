#include "screen/art/controls/layout/panel.h"

#include "screen/art/drawing.h"

void Panel :: AnglePattern(Range* board, Angles symbols) {
    Point* cursor = &board.P1;
    Point* anchor = &board.P2;

    VLine(cursor, anchor->X);
    MoveCursor(cursor);
    Draw(symbols.left);

    HLine(cursor, anchor->Y);
    MoveCursor(cursor);
    Draw(symbols.right);
}

void Panel :: DrawAngles() {
    Range board;
    board.P1.X = BasePoint();

    board.P2 = TopAnchor();
    AnglePattern(&board, TopAngles());

    board.P2 = BottomAnchor();
    AnglePattern(&board, BottomAngles().Swap());
}
