#ifndef SCREEN_ART_CONTROLS_BAR
#define SCREEN_ART_CONTROLS_BAR

#include "common/types.h"
#include "screen/drawing/types/constructs/corners.h"
#include "screen/controls/layout/panel.h"
#include "screen/controls/bar/percentage/percentage.h"
#include "screen/controls/bar/progress.h"
#include "screen/controls/bar/divisions.h"
#include "screen/matrix/change/stapler.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

class Bar : public Panel {
    private:
        Percentage m_percentage;
        Progress m_progress;

        Range placement;
        Point m_cursor;

        Corners m_symbols;
        Stapler m_gun;

        byte m_position;
        bool m_orientation;

        void SetOrientation();

    protected:
        byte BasePoint();

        Point TopAnchor();
        Point BottomAnchor();
        Angles TopAngles();
        Angles BottomAngles();

    public:
        Divisions Line;

        Bar();
        Bar* SetSize(Range* sizes);
        Bar* SetSymbols(Corners* symbols);
        Bar* Orientation(bool vertical);
        Bar* Show();
        Bar* Progress(float basis);
        Bar* ProgressData(float value);
};

#endif
