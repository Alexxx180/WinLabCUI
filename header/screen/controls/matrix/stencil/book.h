#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_BOOK
#define SCREEN_CONTROLS_MATRIX_STENCIL_BOOK

#include <vector>

#include "common/types.h"
#include "screen/matrix/types/point.h"

class Book {
    private:
        void BookMark(byte count);
        byte Head();

    public:
        byte Span = 0, Mark = 0, Pages = 0;

        byte Map(std::vector<Point>& basis);
        void Split(byte column, byte count);
        void Split(byte count);
        void Flip(byte count, char direction);
};

#endif
