#include <string>
#include "input/feedback/verifier.h"
#include "screen/matrix/pen.h"

extern char field;

void InputParameterName(std::wstring);
void InputParameterFeedback(std::wstring);

template<class TYPE>
void InputParameterValue(Verifier<TYPE>* limit) {
    Pen::ink().screen->Page(field);
    Pen::ink().Input(limit);
}

template<class TYPE>
void InputParameter(Verifier<TYPE>* limit, std::string name) {
    std::wstring parameter = texts[name];

    InputParameterName(parameter);
    limit->Edges()->View();

    InputParameterFeedback(parameter);
    Pen::ink().Text(limit->result);
}
