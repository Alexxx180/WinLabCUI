#ifndef SCREEN_CONTROLS_MATRIX_STENCIL
#define SCREEN_CONTROLS_MATRIX_STENCIL

#include <vector>

#include "common/types.h"
#include "screen/controls/matrix/stencil/mapper.h"

class Stencil {
    private:
        std::vector<Mapper> m_forms;
        byte m_form = 0;

        void AssertBounds(byte form);
        Mapper& current();

    public:
        Stencil(std::vector<Mapper> forms);
        short Columns();
        Stencil* Form(byte form);
        Stencil* Span(byte columns);
        Stencil* Page(byte column);
        Stencil* Flip(char direction);
        Stencil* Size(byte padding);
        Stencil* Line(char direction);
        Stencil* Jump(char direction);
        Stencil* Jump();
        Stencil* Line();
        Stencil* Move();
        Stencil* Clear();
        Stencil* Field();
};

#endif
