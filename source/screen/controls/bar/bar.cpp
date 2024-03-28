#include "screen/controls/bar/bar.h"

#include "screen/drawing/drawing.h"

void Bar :: SetOrientation() {
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

byte Bar :: BasePoint() {
    return placement.P1.X;
}

Point Bar :: TopAnchor() {
    return { placement.P1.Y, placement.SumX() };
}
Point Bar :: BottomAnchor() {
    return { placement.SumY(), placement.P1.X };
}

Angles Bar :: TopAngles() {
    return m_symbols.Top;
}
Angles Bar :: BottomAngles() {
    return m_symbols.Bottom;
}

Bar :: Bar() {
    Line.SetPercents(m_percentage.Count())->SetCursor(&m_cursor);

    m_percentage.SetCursor(&m_cursor)->SetStapler(&m_gun);
    m_percentage.MemoryPosition(&m_position);

    m_progress.SetCursor(&m_cursor)->SetStapler(&m_gun);
    m_progress.MemoryPosition(&m_position);
}

Bar* Bar :: SetSize(Range* sizes) {
    placement = *sizes;
    Line.SetSize(&placement);
    m_progress.SetSize(&placement);
    return this;
}

Bar* Bar :: SetSymbols(Corners* symbols) {
    m_symbols = *symbols;
    Line.SetSymbols(symbols);
    return this;
}

Bar* Bar :: Vertical(bool orientation) {
    m_orientation = orientation;
    return this;
}

Bar* Bar :: Show() {
    Line.Show();
    DrawAngles();
    SetOrientation();
    return this;
}

Bar* Bar :: Progress(float basis) {
    m_progress.Update(basis)->MoveProgress();
    m_percentage.Update(basis, m_progress.Get());
    return this;
}

Bar* Bar :: ProgressData(float value) {
    if (Line.Idle()) return this;
    float basis = Line.Divide(value);
    return Progress(basis);
}
