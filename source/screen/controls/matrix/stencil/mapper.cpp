#include "screen/controls/matrix/stencil/mapper.h"

#include "common/types.h"
#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

Mapper :: Mapper(std::vector<Point> basis) {
    m_basis = basis;
    m_cursor = m_basis.at(0);
}

short Mapper :: Columns() { return m_basis.size(); }


short Mapper :: Diff() { return ruler.Diff(m_basis, m_book); }

void Mapper :: Move() { MoveCursor(&m_cursor); }

Point& Mapper :: at() { return m_basis.at(m_book.Mark); }

void Mapper :: Page() { m_cursor.X = m_book.Map(m_basis); }

void Mapper :: Span(byte columns) { m_book.Span = columns; }

void Mapper :: Page(byte column) {
    m_book.Split(column, Columns()); Page();
}

void Mapper :: Flip(char direction) {
    m_book.Flip(Columns(), direction); Page();
}

void Mapper :: Size(byte padding) {
    ruler.Size(padding);
}

void Mapper :: Anchor(char lines) {
    m_cursor.Y = ruler.Jump(at().Y, lines);
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
    short width = Diff();
    char border = 1, baseline = 1;

    m_cursor.X -= border;
    pattern.Pipe(&m_cursor);
    m_cursor.X += border;
    m_cursor.Y += baseline;
    pattern.Decoration(&m_cursor, width);
    m_cursor.Y -= baseline;
    Move();
}
