#include "common/texts/common.h"
#include "common/texts/format.h"
#include "input/prompt/numeric/verifier.h"
#include "screen/matrix/tools.h"

template<typename TYPE>
void NameInput(TYPE result) {
    out->Line()->Move()->Text(L" ", result);
}
template <>
void NameInput(std::string name) { NameInput(texts.at(name)); }

template<typename TYPE>
void ValueOutput(TYPE parameter) {
    out->Page(0)->Span(3)->Move();
    out->Clear()->Move()->Span(1);
    out->Text(L" = ", parameter);
}
template <>
void ValueOutput(std::string name) { ValueOutput(texts.at(name)); }

template<class TYPE>
void ParamInput(Verifier<TYPE>* limit, std::string name) {
    NameInput(name);
    out->Bounds(limit->Edges);
    ValueOutput(limit->result);
}

