#include <string>

#include "input/feedback/verifier.h"

void InputParameterName(std::wstring);
template<typename TYPE>
void InputParameterValue(Verifier<TYPE>* limit);
void InputParameterFeedback(std::wstring);
template<typename TYPE>
void InputParameter(Verifier<TYPE>* limit, std::string name);
