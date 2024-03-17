#include "screen/matrix/markdown.h"
#include "screen/art/controls/grid.h"

Markdown* Markdown :: Screen() {
    Grid borders(&m_frame.SwapXY());
    Booker content(m_forms);
    Pen::ink().Append(borders, content);
    m_forms.clear();
    return this;
}

Markdown* Markdown :: Form() {
    m_forms.push_back(m_pages);
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
    m_positions[flow].shift(&m_frame.P1, &offset.X);
    m_positions[flow].shift(&m_frame.P2, &offset.Y);
    return this;
}

Markdown* Markdown :: Top() {
    m_next = &m_frame.P1;
    return this;
}

Markdown* Markdown :: Bottom() {
    m_next = &m_frame.P2;
    return this;
}

Markdown* Markdown :: Pin(byte flow) {
    m_positions[flow].Margin(&m_booker, &m_next);
    return this;
}

Markdown* Markdown :: Ratio(byte flow, float relation) {
    m_positions[flow].Extend(&m_booker, &m_next);
    return this;
}

Markdown* Markdown :: Margin(byte flow, byte margin) {
    m_positions[flow].Append(&m_booker, margin);
    return this;
}
