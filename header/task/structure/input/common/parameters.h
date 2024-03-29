#include <string>
#include "input/feedback/verifier.h"

void NameInput(std::wstring);
void NameInput(std::string);
void ValueOutput(std::wstring);
void ValueOutput(Typer* limit);

template<class TYPE>
void ParamInput(Verifier<TYPE>* limit, std::string name);
