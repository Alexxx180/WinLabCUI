#ifndef SCREEN_CONTROLS_LAYOUT_GRID_GRID
#define SCREEN_CONTROLS_LAYOUT_GRID_GRID

#include "common/types.h"
#include "screen/controls/layout/box.h"
#include "screen/controls/layout/panel.h"
#include "screen/drawing/types/constructs/frame.h"
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
        Box Rows, Columns;

        Grid();
        Grid(Range* sizes);
        Grid* Show();
};

#endif
