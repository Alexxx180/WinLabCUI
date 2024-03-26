#include "screen/controls/matrix/stencil/mapper.h"

Mapper :: Mapper(std::vector<Point> basis) {
    m_basis = basis;
    m_cursor = m_basis.at(0);
}

void Mapper :: Page(Point canvas) {
    mark = canvas.X;
    pages = canvas.Y;
    m_cursor.X = Merge(mark, pages);
}

Mapper :: Mapper(std::vector<Point> basis) {
    m_basis = basis;
    m_cursor = m_basis.at(0);
    pattern.SetCursor(&m_cursor);
}

byte Mapper :: Merge(byte current, byte repeat) {
    byte last = m_basis.size() - 1;
    byte basis = m_basis.at(current).X;
    byte pattern = m_basis.at(last).X;
    return basis + pattern * repeat;
}

Point Mapper :: Split(byte column, byte count) {
    return { column % count, column / count };
}

short Mapper :: Diff() {
    Point canvas = Split(mark + span, m_basis.size());
    byte next = Merge(canvas.X, pages + canvas.Y);
    byte present = m_basis.at(mark).X;
    return next - present;
}

void Mapper :: Span(byte columns) {
    span = columns;
}

void Mapper :: Page(byte column) {
    Page(Split(m_basis.size(), column));
}

void Mapper :: Flip(char direction) {
    byte count = m_basis.size();
    byte listing = pages * count + mark;
    Page(count, listing + direction);
}

void Mapper :: Anchor(char lines) {
    m_cursor.Y = m_basis.at(mark).Y;
    ruler.Skip(m_cursor.Y, lines);
}

void Mapper :: Jump(char direction) {
    ruler.Jump(m_cursor.Y, direction);
}
