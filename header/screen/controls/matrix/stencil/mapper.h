#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_MAPPER
#define SCREEN_CONTROLS_MATRIX_STENCIL_MAPPER

#include <vector>

#include "common/types.h"
#include "screen/matrix/types/point.h"

class Mapper {
    private:
        byte m_pages, m_mark, m_span;

        void Page(Point canvas);
        byte Merge(byte current, byte repeat);
        Point Split(byte column, byte count);

    protected:
        std::vector<Point> m_basis;
        Point m_cursor;

    public:
        Ruler ruler;
        Pattern pattern;

        Mapper(std::vector<Point> basis);
        short Diff();
        void Span(byte columns);
        void Page(byte column);
        void Flip(char direction);
};

#endif
