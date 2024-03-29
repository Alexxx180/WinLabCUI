#ifndef TASK_STRUCTURE_INPUT_ARRAY_CHOICE_SORT
#define TASK_STRUCTURE_INPUT_ARRAY_CHOICE_SORT

#include <vector>

typedef void (*sort_invokation)(std::vector<short>&);

sort_invokation SortSelect();
void SortChoice();

#endif
