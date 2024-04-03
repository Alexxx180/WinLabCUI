#include "screen/controls/matrix/stencil.h"

#include <stdexcept>

#include "screen/drawing/drawing.h"

void Stencil :: AssertBounds(byte form) {
    if (form >= m_forms.size()) throw std::out_of_range("No form found");
}

Mapper& Stencil :: current() {
    return m_forms.at(m_form);
}

Stencil :: Stencil(std::vector<Mapper> forms) {
    m_forms = forms;
    m_form = 0;
}

Stencil* Stencil :: Form(byte form) {
    AssertBounds(form);
    m_form = form;
    return this;
}

Stencil* Stencil :: Span(byte columns) {
    current().Span(columns);
    return this;
}

Stencil* Stencil :: Page(byte column) {
    current().Page(column);
    return this;
}

Stencil* Stencil :: Flip(char direction) {
    current().Flip(direction);
    return this;
}

Stencil* Stencil :: Size(byte padding) {
    current().ruler.Size(padding);
    return this;
}

Stencil* Stencil :: Line(char direction) {
    current().Anchor(direction);
    return this;
}

Stencil* Stencil :: Jump(char direction) {
    current().Jump(direction);
    return this;
}

Stencil* Stencil :: Jump() { return Jump(-1); }

Stencil* Stencil :: Line() { return Jump(1); }

Stencil* Stencil :: Move() {
    current().Move();
    return this;
}

Stencil* Stencil :: Clear() {
    current().Clear();
    return this;
}

Stencil* Stencil :: Field() {
    current().Field();
    return this;
}
