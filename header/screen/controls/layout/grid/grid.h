#ifndef SCREEN_ART_CONTROLS_LAYOUT_GRID
#define SCREEN_ART_CONTROLS_LAYOUT_GRID

#include "common/types.h"
#include "screen/art/controls/layout/box.h"
#include "screen/art/controls/layout/panel.h"
#include "screen/art/types/frame.h"
#include "screen/matrix/types/range.h"
#include "screen/matrix/types/point.h"

class Grid : public Panel {
private:
    Range m_sizes;

    void Crosses();

protected:
    byte BasePoint();
    Point TopAnchor();
    Point BottomAnchor();
    Angles TopAngles();
    Angles BottomAngles();

public:
    Box Rows;
    Box Columns;

    Grid();
    Grid(Range* sizes);
    Grid* Show();
};

#endif
