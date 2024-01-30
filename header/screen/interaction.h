#ifndef ENTER
#define ENTER 13

#define ESC 27
#define PAGE_UP 73
#define PAGE_DOWN 81
#define END 79
#define HOME 71

#define MAX_BUFFER 5

#include "input/boundary.h"

static Boundary<int> result_limits(0, 536870911);
static const short ACTUAL_MAX = MAX_BUFFER + 2;

#include <vector>
;
char Select(char cancel, char ok);
char Select(std::vector<char> targets);
char Next();
char Next(char target);
char Await(char (*program)(), char target);

#endif
