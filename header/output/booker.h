#ifndef OUTPUT_BOOKER
#define OUTPUT_BOOKER

#include "windows.h"

#include <vector>
#include <iostream>

#include "common/types.h"
#include "screen/art/drawing.h"

class Booker {
private:
    std::vector<std::vector<COORD>> m_basis;

protected:
    COORD m_cursor;
    Range m_page;

    COORD* Current() {
        return &m_basis.at(m_page.P1.Y).at(m_page.P1.X);
    }

    short BasisDiff() {
        short span = m_page.P1.X + m_page.P2.X;
        short next = m_basis.at(m_page.P1.Y).at(span).X;
        return next - Current()->X;
    }

    void PageCheck(short limit) {
        if (limit >= m_basis.at(m_page.P1.Y).size())
            throw std::overflow_error("Span > max columns!");
    }

public:
    const COORD& Cursor() { 
        return m_cursor;
    }

    Booker(std::vector<std::vector<COORD>> basis) {
        m_cursor = basis.at(0).at(0);
        m_basis = basis;
        Form(0)->Span(0)->Page(0)->Size(0);
    }

    Booker* Form(short buffer) {
        if (buffer >= m_basis.size())
            throw std::overflow_error("Selected form not found");
        else
            m_page.P1.Y = buffer;
        return this;
    }

    Booker* Span(short columns) {
        PageCheck(m_page.P1.Y + columns);
        m_page.P2.X = columns;
        return this;
    }

    Booker* Size(short padding) {
        m_page.P2.Y = padding;
        return this;
    }

    Booker* Page() {
        m_page.P1.X += 1;
        PageCheck(m_page.P2.X);
        m_cursor.X = Current()->X;
        return this;
    }

    Booker* Page(short next) {
        m_page.P1.X = next;
        PageCheck(m_page.P2.X);
        m_cursor.X = Current()->X;
        return this;
    }

    Booker* Line() {
        m_cursor.Y += m_page.P2.Y;
        return this;
    }

    Booker* Up() {
        m_cursor.Y -= m_page.P2.Y;
        return this;
    }

    Booker* Line(short skip) {
        m_cursor.Y = Current()->Y;
        m_cursor.Y += m_page.P2.Y * skip;
        return this;
    }

    Booker* Clear() {
        Clean(&m_cursor, BasisDiff());
        return this;
    }

    Booker* Move() {
        MoveCursor(&m_cursor);
        return this;
    }

    Booker* Decoration() {
        Field(&m_cursor, BasisDiff());
        return this;
    }
};

#endif
