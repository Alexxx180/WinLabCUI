#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_RULER
#define SCREEN_CONTROLS_MATRIX_STENCIL_RULER

#include "common/types.h"

class Ruler {
    private:
        byte m_lines;

    public:
        void Size(byte lines);
        void Skip(byte& current, char lines);
        void Jump(byte& current, char direction);
};

#endif
