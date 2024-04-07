#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_MAPPER
#define SCREEN_CONTROLS_MATRIX_STENCIL_MAPPER

#include <vector>

#include "common/types.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/change/liner.h"
#include "screen/controls/matrix/stencil/ruler.h"
#include "screen/controls/matrix/stencil/book.h"
#include "screen/controls/matrix/stencil/pattern.h"

class Mapper {
    private:
        Book m_book;

        void Page();

    protected:
        std::vector<Point> m_basis;
        Point m_cursor = { 0, 0 };

    public:
        Ruler ruler;
        Pattern pattern;

        Point& at();

        Mapper(std::vector<Point> basis);
        void Clear();
        void Field();
        short Columns();
        short Diff();
        void Move();
        void Span(byte columns);
        void Page(byte column);
        void Flip(char direction);
        void Size(byte lines);
        void Anchor(char lines);
        void Jump(char direction);
};

#endif
