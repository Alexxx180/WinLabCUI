#ifndef SCREEN_ART_CONTROLS_BAR
#define SCREEN_ART_CONTROLS_BAR

#include "screen/art/types/stapler.h"
#include "screen/art/controls/bar/percentage.h"
#include "screen/art/controls/bar/progress.h"
#include "screen/art/controls/bar/types/corners.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

class Bar {
private:
    const Percentage m_percentage;
    const Progress m_progress;

    Range placement;
    Point m_cursor;

    Corners m_symbols;
    Stapler m_gun;

    unsigned char* m_position;
    bool m_orientation;

    void SetOrientation() {
        if (m_orientation) {
            m_gun.Set(VLine, HLine);
            m_progress.SetSeparator(&m_symbols.Standing);
            m_percentage.SetOffset(placement.SumX() + 2);
        } else {
            m_gun.Set(HLine, VLine);
            m_progress.SetSeparator(&m_symbols.Lying);
            m_percentage.SetOffset(placement.SumY() + 1);
        }
    }

protected:
    unsigned char BasePoint() { return placement.P1.X; }

    Point TopAnchor() { return { placement.P1.Y, placement.SumX() }; }
    Point BottomAnchor() { return { placement.SumY(), placement.P1.X }; }

    Angles TopAngles() { return m_symbols.Top; }
    Angles BottomAngles() { return m_symbols.Bottom; }

public:
    const Divisions Line;

    Bar() {
        Line.SetPercents(m_percentage.Count())->SetCursor(&m_cursor);

        m_percentage.SetCursor(&m_cursor)->SetStapler(&m_gun);
        m_percentage.MemoryPosition(&m_position);

        m_progress.SetCursor(&m_cursor)->SetStapler(&m_gun);
        m_progress.MemoryPosition(&m_position);
    }

    Bar* SetSize(Range* sizes) {
        placement = *sizes;
        Line.SetSize(&placement);
        m_progress.SetSize(&placement);
        return this;
    }

    Bar* SetSymbols(Corners* symbols) {
        m_symbols = *symbols;
        Line.SetSymbols(symbols);
        return this;
    }

    Bar* Orientation(bool vertical) {
        m_orientation = vertical;
        return this;
    }

    Bar* Show() {
        Line.Draw();
        DrawAngles();
        SetOrientation();
        return this;
    }

    Bar* Progress(float basis) {
        m_progress.Update(basis)->MoveProgress();
        m_percentage.Update(basis, m_progress.Get());
        return this;
    }

    Bar* ProgressData(float value) {
        if (Line.Idle()) return this;

        float basis = value / m_count;
        return Progress(basis);
    }
};

#endif
