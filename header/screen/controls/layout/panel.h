#ifndef SCREEN_ART_CONTROLS_LAYOUT_PANEL
#define SCREEN_ART_CONTROLS_LAYOUT_PANEL

#include "screen/art/drawing.h"
#include "screen/matrix/types/range.h"

class Panel {
    protected:
        virtual byte BasePoint() = 0;

        virtual Point TopAnchor() = 0;
        virtual Point BottomAnchor() = 0;

        virtual Angles TopAngles() = 0;
        virtual Angles BottomAngles() = 0;

        virtual void AnglePattern(Range* board, Angles symbols);
        virtual void DrawAngles();
};

#endif
