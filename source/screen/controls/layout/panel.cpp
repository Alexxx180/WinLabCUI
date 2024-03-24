#include "screen/controls/layout/panel.h"
#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

void Panel :: DrawSide(Liner* liner, Range* board, wchar_t symbol) {
    liner->Margin(&board->P1, &board->P2);
    MoveCursor(&board->P1);
    Draw(symbol);
}

void Panel :: AnglePattern(Range* board, Angles symbols) {
    Liner liner = { HPoint, HLine };
    DrawSide(&liner, board, symbols.left);

    liner.Set(VPoint, VLine);
    DrawSide(&liner, board, symbols.right);
}

void Panel :: DrawAngles() {
    Range board;
    board.P1.X = BasePoint();

    board.P2 = TopAnchor();
    AnglePattern(&board, TopAngles());

    board.P2 = BottomAnchor();
    AnglePattern(&board, BottomAngles().Swap());
}
