#ifndef TASK_STRUCTURE_INPUT_ARRAY_CHOICE_SORT
#define TASK_STRUCTURE_INPUT_ARRAY_CHOICE_SORT

#include <vector>

typedef void (*invokation)();

void ManualInput();
void RandomInput();

invokation InputSelect();
std::vector<short> ArrayInput(short size);

#endif
