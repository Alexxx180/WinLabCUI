#include "task/structure/input/common/parameters.h"

#include <string>

#include "common/types.h"
#include "common/texts/common.h"
#include "input/feedback/verifier.h"
#include "screen/matrix/tools.h"

void InputParameterName(std::wstring name) {
    out->Line()->Move();
    pen->Text(L" ", name);
}

void InputParameterFeedback(std::wstring parameter) {
    out->Page(0)->Move()->Span(3);
    out->Clear()->Move()->Span(1);
    pen->Text(L" = ", parameter);
}
