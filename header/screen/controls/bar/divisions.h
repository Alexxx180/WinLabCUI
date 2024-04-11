#ifndef SCREEN_CONTROLS_BAR_DIVISIONS
#define SCREEN_CONTROLS_BAR_DIVISIONS

#include "common/types.h"
#include "screen/drawing/constructs/corners.h"
#include "screen/drawing/constructs/outlines/borders.h"
#include "screen/matrix/types/change/stapler.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

class Divisions {
    private:
        Range* m_placement;
        Point* m_cursor;

        ushort m_percents, m_step, m_i;
        uint m_count;

        Borders m_horizontal, m_vertical;
        Stapler m_gun;

        void DrawBorder(byte position, wchar_t edge);
        void DrawBorders(Borders* edges, Range* target);

    public:
        Divisions* SetCursor(Point* cursor);
        Divisions* SetSize(Range* sizes);
        Divisions* SetPercents(ushort percents);
        Divisions* SetSymbols(Corners* symbols);
        void Show();
        Divisions* SetStep(uint count); 
        float Divide(float current);
        bool Idle();
};

#endif
