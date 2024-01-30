#ifndef TASK_HELPER
#define TASK_HELPER

#include "windows.h"

#include <vector>

#include "common/types.h"
#include "screen/interaction.h"
#include "input/feedback/verifier.h"
;
extern std::vector<char> table_controls;

void OutputHeader();
void OutputStatus();
void Output(std::vector<Answer> results);
char OutputControl();

#endif
