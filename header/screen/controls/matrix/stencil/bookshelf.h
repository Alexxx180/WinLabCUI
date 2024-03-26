#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_BOOKSHELF
#define SCREEN_CONTROLS_MATRIX_STENCIL_BOOKSHELF

#include "common/types.h"

class Bookshelf {
    protected:
        std::vector<Book> m_forms;

        byte form;

        byte PagesMap(byte nets);
};

#endif
