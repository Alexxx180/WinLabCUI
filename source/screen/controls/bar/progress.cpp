#include "screen/controls/bar/progress.h"
#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

// Orientation independent
void Progress :: Display() {
    Draw(m_symbol);
}

void Progress :: Clear() {
    Clean(m_width);
}

void Progress :: Fill(void (Progress::*operation)()) {
    short i = m_placement->P1.Y;
    short size = m_placement->SumY();

    while (++i < size) {
        VLine(m_cursor, i);
        MoveCursor(m_cursor);
        ((this)->*(operation))();
    }
}

// Orientation dependent
void Progress :: MoveCarriage(byte position) {
    m_gun->progress(m_cursor, position);
    Fill(&Progress::Display);
}

short Progress :: Get() {
    return m_slider;
}

void Progress :: SetSeparator(Separator* separator) {
    m_separator = *separator;
}

Progress* Progress :: SetCursor(Point* cursor) {
    m_cursor = cursor;
    return this;
}

Progress* Progress :: SetSize(Range* placement) {
    m_placement = placement;
    return this;
}

Progress* Progress :: SetStapler(Stapler* gun) {
    m_gun = gun;
    return this;
}

Progress* Progress :: MemoryPosition(byte* memory) {
    m_position = memory;
    return this;
}

Progress* Progress :: Update(float basis) {
    short start = m_placement->P1.X;
    short end = m_placement->P2.X;

    float location = start + basis * end;
    m_slider = static_cast<short>(location);
    return this;
}

void Progress :: MoveProgress() {
    if (m_slider == *m_position) return;

    short i = m_placement->P1.X;
    short size = m_slider - i;

    HLine(m_cursor, i + 1);

    m_width = m_placement->SumX() - i;
    Fill(&Progress::Clear);

    m_symbol = m_separator.Carriage;
    MoveCarriage(m_slider);

    m_symbol = m_separator.Volume;
    for (i = i + m_glare; i < size; i += m_glare)
        MoveCarriage(i);
}
