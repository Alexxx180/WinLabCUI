#include "screen/controls/matrix/pen.h"
#include "common/texts/common.h"

Pen :: Pen() {}

Pen :: quoteptr Pen :: Feedback() {
    return &Pen::Clip;
}

Pen* Pen :: Clip(std::string name) {
    Text(texts.at(name));
    return this;
}

template<typename TYPE>
Pen* Pen :: Bounds(Boundary<TYPE>& limits) {
    Text(L"<", limits.start, L", ", limits.end, L">");
    return this;
}
