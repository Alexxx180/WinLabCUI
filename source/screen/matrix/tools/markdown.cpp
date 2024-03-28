#include "screen/matrix/tools/markdown.h"

#include "screen/controls/bar/bar.h"
#include "screen/controls/matrix/screen.h"
#include "screen/controls/layout/grid/grid.h"

Markdown :: Markdown() {
    m_positions[X].Set(HPoint, HLine, HRatio);
    m_positions[Y].Set(VPoint, VLine, VRatio);
}

Markdown* Markdown :: Clear() {
    m_forms.clear();
    return this;
}

Bar Markdown :: ProgressBar() {
    return progress;
}

Screen Markdown :: Result() {
    Screen screen;
    screen.back = new Grid(&m_next.SwapXY());
    screen.out = new Stencil(m_forms);
    return screen;
}

Markdown* Markdown :: Form() {
    Mapper book(m_pages);
    m_forms.push_back(book);
    m_pages.clear();
    return this;
}

Markdown* Markdown :: Page() {
    m_pages.push_back(m_current);
    return this;
}

Markdown* Markdown :: Base(Range* origin) {
    m_origin = *origin;
    return this;
}

Markdown* Markdown :: Origin() {
    m_next = m_origin;
    return this;
}

Markdown* Markdown :: Place(Shifter* pos, byte p1, byte p2) {
    pos->shift(&m_next.P1, p1);
    pos->shift(&m_next.P2, p2);
    return this;
}

Markdown* Markdown :: Shift(byte flow, byte p2, byte size) {
    Shifter* pos = &m_positions[flow];
    p2 += pos->extract(&m_next.P2);
    return Place(m, p2, p2 + size);
}

Markdown* Markdown :: Flatten(byte flow, byte margin, float ratio) {
    Shifter* pos = &m_positions[flow];
    byte p1 = pos->extract(&m_next.P1) + margin * ratio;
    byte p2 = pos->extract(&m_next.P2) - margin * (1.0f - ratio);
    return Place(pos, p1, p2);
}

Markdown* Markdown :: Top(byte flow) {
    m_positions[flow].Margin(&m_current, &m_next.P1);
    return this;
}

Markdown* Markdown :: Bot(byte flow) {
    m_positions[flow].Margin(&m_current, &m_next.P2);
    return this;
}

Markdown* Markdown :: Top() {
    return Top(X)->Top(Y);
}

Markdown* Markdown :: Bot() {
    return Bot(X)->Bot(Y);
}

Markdown* Markdown :: Relate(byte flow, float relation) {
    m_positions[flow].Extend(&m_current, relation);
    return this;
}

Markdown* Markdown :: Margin(byte flow, byte margin) {
    m_positions[flow].Append(&m_current, margin);
    return this;
}
