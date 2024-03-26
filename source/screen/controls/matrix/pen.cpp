#include "screen/controls/matrix/pen/formatter.h"
#include "common/texts/common.h"

Pen :: Pen() {}

static Pen* Pen :: ink() {
    static Pen instance;
    return &instance;
}

quoteptr Pen :: Feedback() {
    return &Pen::Quote;
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
