#ifndef SCREEN_ART_CONTROLS_BAR_DIVISIONS
#define SCREEN_ART_CONTROLS_BAR_DIVISIONS

#include "screen/art/drawing.h"
#include "screen/art/controls/bar/types/corners.h"
#include "screen/art/types/stapler.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

class Divisions {
private:
    Range* m_placement;
    Point* m_cursor;

    unsigned short m_percents, m_step, m_i;
    unsigned int m_count;

    Borders m_horizontal, m_vertical;
    Stapler m_gun;

    void DrawBorder(unsigned char position, wchar_t edge) {
        m_gun.pins(m_cursor, position);
        MoveCursor(m_cursor);
        Draw(edge);
    }

    void DrawBorders(Borders* edges, Range* target) {
        short i = target->P1.X;
        short size = target->SumX();

        short start = target->P1.Y;
        short end = target->SumY();

        while (++i < size) {
            m_gun.progress(m_cursor, i);
            DrawBorder(start, edges->Front);
            DrawBorder(end, edges->Back);
        }
    }

public:
    Divisions* SetCursor(Point* cursor) {
        m_cursor = cursor;
        return this;
    }

    Divisions* SetSize(Range* sizes) {
        m_placement = sizes;
        return this;
    }

    Divisions* SetPercents(unsigned short percents) {
        m_percents = percents;
        return this;
    }

    Divisions* SetSymbols(Corners* symbols) {
        m_horizontal = symbols->Horizontal;
        m_vertical = symbols->Vertical;
        return this;
    }

    void Show() {
        m_gun.Set(HLine, VLine);
        DrawBorders(&m_horizontal, m_placement);

        Range reverse = m_placement->SwapSizes();

        m_gun.Set(VLine, HLine);
        DrawBorders(&m_vertical, &reverse);
    }

    Divisions* SetStep(unsigned int count) {
        m_count = count;

        float proportion = m_count / m_percents;
        m_step = static_cast<unsigned short>(proportion);
        m_i = m_step - 1;

        return this;
    }

    float Divide(float current) { return current / m_count; }

    bool Idle() {
        bool idle = ++m_i < m_step;

        if (!idle) m_i = 0;

        return idle;
    }
};

#endif
