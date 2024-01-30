#ifndef TASK_STRUCTURE_INPUT
#define TASK_STRUCTURE_INPUT

#include <string>

#include "common/types.h"
#include "input/boundary.h"
#include "input/feedback/verifier.h"
;
extern Verifier<float>* floating;

void InputFloat(std::string name);
Loop InputLoop(const Boundary<float> *const initial, std::string name[3]);
Loop2 Input();

#endif
