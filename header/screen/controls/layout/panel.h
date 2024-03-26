#ifndef SCREEN_ART_CONTROLS_LAYOUT_PANEL
#define SCREEN_ART_CONTROLS_LAYOUT_PANEL

#include "screen/drawing/constructs/outlines/angles.h"
#include "screen/matrix/types/range.h"
#include "screen/matrix/types/change/liner.h"

class Panel {
    private:

    protected:
        virtual byte BasePoint() = 0;

        virtual Point TopAnchor() = 0;
        virtual Point BottomAnchor() = 0;

        virtual Angles TopAngles() = 0;
        virtual Angles BottomAngles() = 0;

        virtual void DrawSide(Liner* liner, Range* board, wchar_t symbol);
        virtual void AnglePattern(Range* board, Angles symbols);
        virtual void DrawAngles();
};

#endif
