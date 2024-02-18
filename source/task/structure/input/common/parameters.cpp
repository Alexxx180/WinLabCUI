#include "task/structure/input/common/parameters.h"

#include <string>

#include "common/texts/common.h"
#include "input/feedback/verifier.h"
#include "screen/matrix/pen.h"

char field = 3;

void InputParameterName(std::wstring name) {
    Pen::ink().screen->Line()->Move();
    Pen::ink().Text(L" ", name);
}

void InputParameterFeedback(std::wstring parameter) {
    Pen::ink().screen->Page(0)->Move()->Span(field);
    Pen::ink().screen->Clear()->Move()->Span(1);
    Pen::ink().Text(L" = ", parameter);
}
