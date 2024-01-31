#ifndef TASK_STRUCTURE_INPUT
#define TASK_STRUCTURE_INPUT

#include <string>

#include "common/types.h"
#include "input/boundary.h"
#include "input/feedback/verifier.h"

extern Verifier<float>* floating;
extern Verifier<short>* numeric;

void SetStatusSignal(); 
template<typename TYPE>
void InputParameter(Verifier<TYPE>* limit, std::string name);
Period Input();

#endif
