#ifndef SCREEN_ART_CONTROLS_PANEL
#define SCREEN_ART_CONTROLS_PANEL

#include "screen/art/drawing.h"

class Panel {
    protected:
        virtual unsigned char BasePoint() = 0;

        virtual Point TopAnchor() = 0;
        virtual Point BottomAnchor() = 0;

        virtual Angles TopAngles() = 0;
        virtual Angles BottomAngles() = 0;

        virtual void AnglePattern(Point* cursor, Point* anchor, Angles symbols) {
            VLine(cursor, anchor->X);
            MoveCursor(cursor);
            Draw(symbols.left);

            HLine(cursor, anchor->Y);
            MoveCursor(cursor);
            Draw(symbols.right);
        }

        virtual void DrawAngles() {
            Point cursor, anchor;
            cursor.X = BasePoint();

            anchor = TopAnchor();
            AnglePattern(&cursor, &anchor, TopAngles());

            anchor = BottomAnchor();
            AnglePattern(&cursor, &anchor, BottomAngles());
        }
};

#endif
