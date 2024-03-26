#include "screen/controls/matrix/stencil.h"

void Stencil :: AssertBounds(byte form) {
    if (form >= m_forms.size())
        throw std::overflow_error("Selected form not found");
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
    current.Span(columns);
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
    current().pattern.Move();
    return this;
}

Stencil* Stencil :: Clear() {
    Mapper& book = current();
    short width = book.Diff();
    book.pattern.Move();
    book.pattern.Clear(width);
    return this;
}

Stencil* Stencil :: Field() {
    Mapper& book = current();
    short width = book.Diff();
    char offset = 1;
    book.pattern.Shift(-offset);
    book.pattern.Pipe();
    book.pattern.Shift(width + offset);
    book.pattern.Decoration(1, width);
    return this;
}
