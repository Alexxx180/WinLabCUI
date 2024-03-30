#ifndef TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT
#define TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT

#include <vector>

typedef void (*invokation)();

void ManualInput();
void RandomInput();

invokation InputSelect();
std::vector<short> ArrayInput(short size);

#endif
