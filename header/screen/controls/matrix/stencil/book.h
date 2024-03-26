#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_BOOK
#define SCREEN_CONTROLS_MATRIX_STENCIL_BOOK

#include "common/types.h"

class Book {
    protected:
        std::vector<Point> m_basis;

        std::vector<std::vector<Point>> m_basis;
        byte form, line, pages, mark, span;
        Point m_cursor;

        static const wchar_t pipe_vertical = L'|';
        static const wchar_t pipe_horizontal = L'‾';

        byte PagesMap(byte nets);
};

#endif
