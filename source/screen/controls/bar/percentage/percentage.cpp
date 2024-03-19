#include "screen/controls/bar/percentage/percentage.h"
#include "screen/drawing/drawing.h"

void Percentage :: PercentagePosition() {
    m_gun->pins(m_cursor, m_offset);
    m_gun->progress(m_cursor, *m_position);
    MoveCursor(m_cursor);
}

void Percentage :: ClearPercentage() {
    if (*m_position >= 0) {
        PercentagePosition();
        Clean(m_percentage.Width);
    }
}

void Percentage :: SetPercentage(float basis) {
    PercentagePosition();
    m_percentage.Print(basis);
}

Percentage :: Percentage() {
    m_percentage.Calculate(100.0f);
}

ushort Percentage :: Count() {
    return m_percentage.Count;
}

void Percentage :: SetOffset(byte offset) {
    m_offset = offset;
}

Percentage* Percentage :: MemoryPosition(byte* memory) {
    m_position = memory;
    return this;
}

Percentage* Percentage :: SetCursor(Point* cursor) {
    m_cursor = cursor;
    return this;
}

Percentage* Percentage :: SetStapler(Stapler* gun) {
    m_gun = gun;
    return this;
}

void Percentage :: Update(float basis, byte position) {
    ClearPercentage();
    *m_position = position;
    SetPercentage(basis);
}
