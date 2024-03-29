#ifndef TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT
#define TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT

#include <vector>

typedef void (*sort_invokation)(std::vector<short>&);

invokationVector DetermineSort();
void StartArraySort();

#endif
