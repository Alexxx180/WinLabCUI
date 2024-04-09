#include "task/structure/input/common/parameters.h"

#include "common/texts/common.h"
#include "screen/matrix/tools.h"

void NameInput(std::wstring name) {
    out->Line()->Move()->Text(L" ", name);
}

void NameInput(std::string name) {
    NameInput(texts.at(name));
}

void ValueOutput(std::wstring parameter) {
    out->Page(0)->Move();
    out->Span(3)->Clear();
    out->Span(1)->Move();
    out->Text(L" = ", parameter);
}

void ValueOutput(std::string name) {
    ValueOutput(texts.at(name));
}

void ValueInput(Typer* field) {
    out->Page(3);
    field->Input();
}

template<class TYPE>
void ParamInput(Verifier<TYPE>* limit, std::string name) {
    NameInput(name);
    out->Bounds(limit->Edges);
    ValueOutput(limit->result);
}
