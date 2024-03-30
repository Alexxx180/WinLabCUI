#include "task/structure/input/common/parameters.h"

#include "common/texts/common.h"
#include "screen/matrix/tools.h"

void NameInput(std::wstring name) {
    out->Line()->Move();
    pen->Text(L" ", name);
}

void NameInput(std::string name) {
    NameInput(texts.at(name));
}

void ValueOutput(std::wstring parameter) {
    out->Page(0)->Move()->Span(3);
    out->Clear()->Move()->Span(1);
    pen->Text(L" = ", parameter);
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
    pen->Bounds(limit->Edges);
    ValueOutput(limit->result); // name
}
