#include "task/structure/input.h"

#include <math.h>
#include <string>

#include "input/boundary.h"
#include "input/feedback/verifier.h"
#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "common/types.h"
#include "common/texts/common.h"
#include "output/format/pen.h"

void InputParameterName(std::wstring) {
    Pen::ink().screen->Line()->Move();
    Pen::ink().Text(L" ", parameter);
}

template<typename TYPE>
void InputParameterValue(Verifier<TYPE>* limit) {
    Pen::ink().screen->Page(field);
    Pen::ink().Input(limit);
}

void InputParameterFeedback(std::wstring) {
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
