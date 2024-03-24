#ifndef SCREEN_MATRIX_STENCIL
#define SCREEN_MATRIX_STENCIL

#include <vector>

#include "common/types.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/book.h"

class Stencil {
    private:
        std::vector<std::vector<Point>> m_basis;
        Point m_cursor;
        Book m_book;

        Point* NextPoint(byte span);
        Point* Current();
        void PagesEnd(byte limit);

    protected:
        static const wchar_t pipe_horizontal = L'|';
        static const wchar_t pipe_vertical = L'‾';

        short BasisDiff();
        Booker* Field(Point space, short size);
        Booker* SkipLine(char lines, char direction);
        Booker* BookMark(char skip, char direction);

    public:
        const Point& Cursor();
        Booker(std::vector<std::vector<Point>> basis);
        Booker* Form(byte buffer);
        Booker* Span(byte columns);
        Booker* Page(byte next);
        Booker* Page();
        Booker* Size(byte padding);
        Booker* Line();
        Booker* Up();
        Booker* Line(char skip);
        Booker* Up(char skip);
        Booker* Move();
        Booker* Clear();
        Booker* Decoration();
};

#endif
