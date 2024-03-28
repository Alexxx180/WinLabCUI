#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_PATTERN
#define SCREEN_CONTROLS_MATRIX_STENCIL_PATTERN

#include "screen/matrix/types/point.h"

class Pattern {
    private:
        static const wchar_t pipe_horizontal = L'|';
        static const wchar_t pipe_vertical = L'‾';

        Point* m_cursor;

    public:
        void SetCursor(Point* cursor);
        void Move();
        void Clear(short width);
        void Shift(short width);
        void Decoration(char baseline, short width);
        void Pipe();
};

#endif
