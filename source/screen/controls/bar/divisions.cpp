#include "screen/controls/bar/divisions.h"
#include "screen/art/drawing.h"

void Divisions :: DrawBorder(byte position, wchar_t edge) {
    m_gun.pins(m_cursor, position);
    MoveCursor(m_cursor);
    Draw(edge);
}

void Divisions :: DrawBorders(Borders* edges, Range* target) {
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

Divisions* Divisions :: SetCursor(Point* cursor) {
    m_cursor = cursor;
    return this;
}

Divisions* Divisions :: SetSize(Range* sizes) {
    m_placement = sizes;
    return this;
}

Divisions* Divisions :: SetPercents(ushort percents) {
    m_percents = percents;
    return this;
}

Divisions* Divisions :: SetSymbols(Corners* symbols) {
    m_horizontal = symbols->Horizontal;
    m_vertical = symbols->Vertical;
    return this;
}

void Divisions :: Show() {
    m_gun.Set(HLine, VLine);
    DrawBorders(&m_horizontal, m_placement);

    Range reverse = m_placement->SwapSizes();

    m_gun.Set(VLine, HLine);
    DrawBorders(&m_vertical, &reverse);
}

Divisions* Divisions :: SetStep(uint count) {
    m_count = count;

    float proportion = m_count / m_percents;
    m_step = static_cast<ushort>(proportion);
    m_i = m_step - 1;

    return this;
}

float Divisions :: Divide(float current) {
    return current / m_count;
}

bool Divisions :: Idle() {
    bool idle = ++m_i < m_step;
    if (!idle) m_i = 0;
    return idle;
}
