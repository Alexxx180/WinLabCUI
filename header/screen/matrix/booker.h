#ifndef SCREEN_MATRIX_BOOKER
#define SCREEN_MATRIX_BOOKER

#include <vector>
#include <iostream>

#include "screen/art/drawing.h"
#include "screen/matrix/types/point.h"

class Booker {
private:
    std::vector<std::vector<Point>> m_basis;

protected:
    Point m_cursor;
    Book m_book;

    Point* Current() {
        unsigned char form, page;
        form = m_book.Form;
        page = m_book.Page;
        return &m_basis.at(form).at(page);
    }

    short BasisDiff() {
        unsigned char form, page, previous, next;
        form = m_book.Form;

        page = m_book.Page;
        previous = m_basis.at(form).at(page).X

        page += m_book.Span;
        next = m_basis.at(form).at(page).X;

        return next - previous;
    }

    void PageCheck(unsigned char limit) {
        if (limit >= m_basis.at(m_book.Form).size())
            throw std::overflow_error("Span > max columns!");
    }

public:
    const Point& Cursor() { return m_cursor; }

    Booker(std::vector<std::vector<Point>> basis) {
        m_cursor = basis.at(0).at(0);
        m_basis = basis;
        Form(0)->Span(0)->Page(0)->Size(0);
    }

    Booker* Form(unsigned char buffer) {
        if (buffer >= m_basis.size())
            throw std::overflow_error("Selected form not found");
        else
            m_book.Form = buffer;
        return this;
    }

    Booker* Span(unsigned char columns) {
        PageCheck(m_book.Page + columns);
        m_book.Span = columns;
        return this;
    }

    Booker* Page(unsigned char next) {
        m_book.Page = next;
        PageCheck(m_book.Span);
        m_cursor.X = Current()->X;
        return this;
    }

    Booker* Page() {
        Page(m_book.Page + 1);
        return this;
    }

    Booker* Size(unsigned char padding) {
        m_page.Line = padding;
        return this;
    }

    Booker* Line() {
        m_cursor.Y += m_page.Line;
        return this;
    }

    Booker* Up() {
        m_cursor.Y -= m_page.Line;
        return this;
    }

    Booker* Line(char skip) {
        m_cursor.Y = Current()->Y;
        m_cursor.Y += m_page.Line * skip;
        return this;
    }

    Booker* Move() {
        MoveCursor(&m_cursor);
        return this;
    }

    Booker* Clear() {
        Move();
        Clean(BasisDiff());
        return this;
    }

    Booker* Decoration() {
        Move();
        Field(BasisDiff());
        Move();
        return this;
    }
};

#endif
