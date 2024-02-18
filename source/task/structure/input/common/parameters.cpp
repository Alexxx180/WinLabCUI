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

template<typename TYPE>
void InputParameterValue(Verifier<TYPE>* limit) {
    Pen::ink().screen->Page(field);
    Pen::ink().Input(limit);
}

void InputParameterFeedback(std::wstring parameter) {
    Pen::ink().screen->Page(0)->Move()->Span(field);
    Pen::ink().screen->Clear()->Move()->Span(1);
    Pen::ink().Text(L" = ", parameter);
}

template<typename TYPE>
void InputParameter(Verifier<TYPE>* limit, std::string name) {
    std::wstring parameter = texts[name];

    InputParameterName(parameter);

    limit->Edges()->View();

    InputParameterFeedback(parameter);
    Pen::ink().Text(limit->result);
}
