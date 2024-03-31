#ifndef SCREEN_ART_CONTROLS_LAYOUT_PANEL
#define SCREEN_ART_CONTROLS_LAYOUT_PANEL

#include "screen/drawing/constructs/outlines/angles.h"
#include "screen/matrix/types/point.h"

class Panel {
    protected:
        virtual byte BasePoint() = 0;

        virtual Point TopAnchor() = 0;
        virtual Point BottomAnchor() = 0;

        virtual Angles TopAngles() = 0;
        virtual Angles BottomAngles() = 0;

        virtual void Vertice(Point* cursor, wchar_t symbol);
        virtual void DrawAngles();
};

#endif
