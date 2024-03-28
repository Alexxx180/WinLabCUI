#include "screen/matrix/tools/markdown.h"

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

Screen Markdown :: Result() {
    Screen screen;
    screen.back = new Grid(&m_frame.SwapXY());
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
    m_pages.push_back(m_booker);
    return this;
}

Markdown* Markdown :: Base(Range* origin) {
    m_origin = *origin;
    return this;
}

Markdown* Markdown :: Origin() {
    m_frame = m_origin;
    return this;
}

Markdown* Markdown :: Shift(byte flow, Point offset) {
    offset.X += m_positions[flow].positions(&m_frame.P2);
    offset.Y += offset.X;
    m_positions[flow].shift(&m_frame.P1, offset.X);
    m_positions[flow].shift(&m_frame.P2, offset.Y);
    return this;
}

Markdown* Markdown :: Top() {
    m_next = &m_frame.P1;
    return this;
}

Markdown* Markdown :: Bot() {
    m_next = &m_frame.P2;
    return this;
}

Markdown* Markdown :: Pin(byte flow) {
    m_positions[flow].Margin(&m_booker, m_next);
    return this;
}

Markdown* Markdown :: Relate(byte flow, float relation) {
    m_positions[flow].Extend(&m_booker, relation);
    return this;
}

Markdown* Markdown :: Margin(byte flow, byte margin) {
    m_positions[flow].Append(&m_booker, margin);
    return this;
}
