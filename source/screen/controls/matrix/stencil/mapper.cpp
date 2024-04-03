#include "screen/controls/matrix/stencil/mapper.h"

#include "common/types.h"
#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

Mapper :: Mapper(std::vector<Point> basis) {
    m_basis = basis;
    m_cursor = m_basis.at(0);
}

short Mapper :: Diff() { return ruler.Diff(m_basis, m_book); }

void Mapper :: Move() { MoveCursor(&m_cursor); }

Point& Mapper :: at() { return m_basis.at(m_book.Mark); }

void Mapper :: Page() { m_cursor.X = m_book.Map(m_basis); }

void Mapper :: Span(byte columns) { m_book.Span = columns; }

void Mapper :: Page(byte column) {
    m_book.Split(column, m_basis.size()); Page();
}

void Mapper :: Flip(char direction) {
    m_book.Flip(m_basis.size(), direction); Page();
}

void Mapper :: Anchor(char lines) {
    m_cursor.Y = ruler.Skip(at().Y, lines);
}

void Mapper :: Jump(char direction) {
    m_cursor.Y = ruler.Jump(m_cursor.Y, direction);
}

void Mapper :: Clear() {
    Move();
    short width = Diff();
    pattern.Clear(&m_cursor, width);
}

void Mapper :: Field() {
    short width = Diff() + 1;
    char baseline = 1;

    m_cursor.X -= width;
    pattern.Pipe(&m_cursor);
    m_cursor.X += width;
    m_cursor.Y += baseline;
    pattern.Decoration(&m_cursor, width);
    m_cursor.Y -= baseline;
    Move();
}
