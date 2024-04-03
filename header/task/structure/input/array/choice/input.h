#ifndef TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT
#define TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT

#include <vector>

typedef char (*input_type)();

void ManualInput();
void RandomInput();

std::vector<short> ArrayInput(short size);

#endif
