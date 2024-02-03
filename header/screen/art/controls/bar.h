#ifndef SCREEN_ART_BAR
#define SCREEN_ART_BAR

#include <vector>

#include "screen/art/drawing.h"
#include "common/types.h"
#include "input/boundary.h"

#include "screen/art/controls/bar/percentage.h"

#include <conio.h>

class Bar {
private:
    const Percentage m_percentage;
    const Progress m_progress;

    COORD m_cursor, m_slider, m_optimization = { 0, -1 };
    unsigned char m_step;
    float m_count;
    bool m_orientation;

    Corners m_symbols;
    Stapler m_gun;

    void Drawing(wchar_t symbol) {
        MoveCursor(&m_cursor);
        Draw(symbol);
    }

    void Slide(short position) {
        m_gun.progress(&m_cursor, position);
    }

    void Extend(short position) {
        m_gun.pins(&m_cursor, position);
    }

    // Depends on sliding methods
    void DrawEdges(Edges* edges, Range* target) {
        short i = target->P1.X;
        short size = target->SumX();

        short start = target->P1.Y;
        short end = target->SumY();

        while (++i < size) {
            Slide(i);

            Extend(start);
            Drawing(edges->left);

            Extend(end);
            Drawing(edges->right);
        }
    }

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
    Range placement;

    Bar* SetSize(Range* sizes) {
        placement = *sizes;
        return this;
    }

    Bar* SetSymbols(Corners* symbols) {
        m_symbols = *symbols;
        return this;
    }

    // Sets the dependencies
    Bar* Orientation(bool vertical) {
        m_orientation = vertical;
        return this;
    }

    Bar* SetDivisions(unsigned int count) {
        m_optimization.X = static_cast<short>(count / m_percentage.X);
        m_step = m_optimization.X - 1;
        m_count = count;
        return this;
    }

    Bar* Show() {
        m_gun.Set(HLine, VLine);
        DrawEdges(&m_symbols.horizontal, &placement);

        Range reverse = placement.SwapSizes();

        m_gun.Set(VLine, HLine);
        DrawEdges(&m_symbols.vertical, &reverse);

        DrawAngles();
        SetOrientation();
        return this;
    }

    Bar* Progress(float basis) {
        m_progress.Update(basis);
        m_progress.MoveProgress();
        m_percentage.Update(basis, m_progress.Get());
        return this;
    }

    Bar* ProgressData(float value) {
        if (++m_step < m_optimization.X)
            return this;

        if (m_step > 0) m_step = 0;

        float basis = value / m_count;
        return Progress(basis);
    }
};

#endif
