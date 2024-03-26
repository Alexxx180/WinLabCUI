#include "screen/controls/matrix/stencil.h"

#include <iostream>

#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

Stencil* Stencil :: Field(Point space, short size) {
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

Point* Stencil :: NextPoint(byte span) {
    return &m_basis.at(m_book.Form).at(span);
}

Point* Stencil :: Current() {
    return NextPoint(m_book.Page);
}

short Stencil :: BasisDiff() {
    byte present = Current()->X;
    byte next = NextPoint(m_book.Page + m_book.Span)->X;
    return next - present;
}

void Stencil :: PagesEnd(byte pointing) {
    byte limit = m_basis.at(m_book.Form).size();
    if (pointing >= limit)
        throw std::overflow_error("Span > max columns!");
}

Stencil* Stencil :: SkipLine(char lines, char direction) {
    m_cursor.Y += lines * direction;
    return this;
}

Stencil* Stencil :: BookMark(char skip, char direction) {
    m_cursor.Y = Current()->Y;
    return SkipLine(m_book.Line * skip, direction);
}

const Point& Stencil :: Cursor() {
    return m_cursor;
}

Stencil :: Stencil(std::vector<std::vector<Point>> basis) {
    m_cursor = basis.at(0).at(0);
    m_basis = basis;
    m_book = { 0, 0, 0, 0 };
}

Stencil* Stencil :: Form(byte buffer) {
    if (buffer >= m_basis.size())
        throw std::overflow_error("Selected form not found");
    else
        m_book.Form = buffer;
    return this;
}

Stencil* Stencil :: Span(byte columns) {
    PagesEnd(m_book.Page + columns);
    m_book.Span = columns;
    return this;
}

Stencil* Stencil :: Page(byte column) {
    PagesEnd(column + m_book.Span);
    m_book.Page = column;
    m_cursor.X = Current()->X;
    return this;
}

Stencil* Stencil :: Page() {
    return Page(m_book.Page + 1);
}

Stencil* Stencil :: Size(byte padding) {
    m_book.Line = padding;
    return this;
}

Stencil* Stencil :: Line() {
    return SkipLine(m_book.Line, 1);
}

Stencil* Stencil :: Up() {
    return SkipLine(m_book.Line, -1);
}

Stencil* Stencil :: Slide(char lines) {
    return SkipLine(m_book.Line, lines);
}

Stencil* Stencil :: Line(char skip) {
    return BookMark(skip, 1);
}

Stencil* Stencil :: Up(char skip) {
    return BookMark(skip, -1);
}

Stencil* Stencil :: Move() {
    MoveCursor(&m_cursor);
    return this;
}

Stencil* Stencil :: Clear() {
    Move();
    Clean(BasisDiff());
    return this;
}

Stencil* Stencil :: Decoration() {
    return Move()->Field(m_cursor, BasisDiff())->Move();
}
