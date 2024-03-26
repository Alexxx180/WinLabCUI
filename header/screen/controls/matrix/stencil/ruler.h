#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_RULER
#define SCREEN_CONTROLS_MATRIX_STENCIL_RULER

#include "common/types.h"

class Ruler {
    private:
        byte m_lines;

    public:
        void Size(byte lines);
        byte Skip(byte current, char lines, char direction);
        byte Skip(byte current, char direction);
};

#endif
