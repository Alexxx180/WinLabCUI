#ifndef SCREEN_ART_CONTROLS_PANEL
#define SCREEN_ART_CONTROLS_PANEL

#include "screen/art/drawing.h"

class Panel {
    protected:
        unsigned char BasePoint() = 0;

        Point TopAnchor() = 0;
        Point BottomAnchor() = 0;

        Angles TopAngles() = 0;
        Angles BottomAngles() = 0;

        void AnglePattern(Point* cursor, Point* anchor, Angles symbols) {
            VLine(&cursor, anchor->X);
            MoveCursor(&cursor);
            Draw(symbols.left);

            HLine(&cursor, anchor->Y);
            MoveCursor(&cursor);
            Draw(symbols.right);
        }

        void DrawAngles() {
            Point cursor, anchor;
            cursor.X = BasePoint();

            anchor = TopAnchor();
            AnglePattern(&cursor, &anchor, TopAngles());

            anchor = BottomAnchor();
            AnglePattern(&cursor, &anchor, BottomAngles());
        }
};

#endif
