#include "screen/matrix/booker.h"

#include <iostream>

#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

Booker* Booker :: Field(Point space, short size) {
    space.X--;
    MoveCursor(&space);
    Draw(pipe_horizontal);
    space.Y++;

    while (--size >= 0) {
        space.X++;
        MoveCursor(&space);
        Draw(pipe_vertical); 
    }
    return this;
}

Point* Booker :: NextPoint(byte span) {
    return &m_basis.at(m_book.Form).at(span);
}

Point* Booker :: Current() {
    return NextPoint(m_book.Page);
}

short Booker :: BasisDiff() {
    byte present = Current()->X;
    byte next = NextPoint(m_book.Page + m_book.Span)->X;
    return next - present;
}

void Booker :: PagesEnd(byte pointing) {
    byte limit = m_basis.at(m_book.Form).size();
    if (pointing >= limit)
        throw std::overflow_error("Span > max columns!");
}

Booker* Booker :: SkipLine(char lines, char direction) {
    m_cursor.Y += lines * direction;
    return this;
}

Booker* Booker :: BookMark(char skip, char direction) {
    m_cursor.Y = Current()->Y;
    return SkipLine(m_book.Line * skip, direction);
}

const Point& Booker :: Cursor() {
    return m_cursor;
}

Booker :: Booker(std::vector<std::vector<Point>> basis) {
    m_cursor = basis.at(0).at(0);
    m_basis = basis;
    m_book = { 0, 0, 0, 0 };
}

Booker* Booker :: Form(byte buffer) {
    if (buffer >= m_basis.size())
        throw std::overflow_error("Selected form not found");
    else
        m_book.Form = buffer;
    return this;
}

Booker* Booker :: Span(byte columns) {
    PagesEnd(m_book.Page + columns);
    m_book.Span = columns;
    return this;
}

Booker* Booker :: Page(byte column) {
    PagesEnd(column + m_book.Span);
    m_book.Page = column;
    m_cursor.X = Current()->X;
    return this;
}

Booker* Booker :: Page() {
    return Page(m_book.Page + 1);
}

Booker* Booker :: Size(byte padding) {
    m_book.Line = padding;
    return this;
}

Booker* Booker :: Line() {
    return SkipLine(m_book.Line, 1);
}

Booker* Booker :: Up() {
    return SkipLine(m_book.Line, -1);
}

Booker* Booker :: Slide(char lines) {
    return SkipLine(m_book.Line, lines);
}

Booker* Booker :: Line(char skip) {
    return BookMark(skip, 1);
}

Booker* Booker :: Up(char skip) {
    return BookMark(skip, -1);
}

Booker* Booker :: Move() {
    MoveCursor(&m_cursor);
    return this;
}

Booker* Booker :: Clear() {
    Move();
    Clean(BasisDiff());
    return this;
}

Booker* Booker :: Decoration() {
    return Move()->Field(m_cursor, BasisDiff())->Move();
}
