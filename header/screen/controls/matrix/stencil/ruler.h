#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_RULER
#define SCREEN_CONTROLS_MATRIX_STENCIL_RULER

#include <vector>

#include "common/types.h"
#include "screen/matrix/types/point.h"
#include "screen/controls/matrix/stencil/book.h"

class Ruler {
    private:
        byte m_lines = 0;

    public:
        void Size(byte lines);
        byte Skip(byte current, char lines);
        byte Jump(byte current, char direction);
        short Diff(std::vector<Point>& basis, Book next);
};

#endif
