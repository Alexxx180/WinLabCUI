#ifndef SCREEN_CONTROLS_MATRIX_STENCIL
#define SCREEN_CONTROLS_MATRIX_STENCIL

#include <vector>

#include "common/types.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/book.h"

class Stencil {
    private:
        std::vector<std::vector<Point>> m_basis;

        std::vector<Book> m_forms;
        byte form;

        Point* NextPoint(byte span);
        Point* Current();
        void PagesEnd(byte limit);

    protected:


        short BasisDiff();
        Stencil* Field(Point space, short size);
        Stencil* SkipLine(char lines, char direction);
        Stencil* BookMark(char skip, char direction);

    public:
        const Point& Cursor();
        Stencil(std::vector<std::vector<Point>> basis);
        Stencil* Form(byte buffer);
        Stencil* Span(byte columns);
        Stencil* Page(byte next);
        Stencil* Page();
        Stencil* Size(byte padding);
        Stencil* Line();
        Stencil* Up();
        Stencil* Line(char skip);
        Stencil* Up(char skip);
        Stencil* Move();
        Stencil* Clear();
        Stencil* Decoration();
};

#endif
