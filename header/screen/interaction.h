#ifndef ENTER
#define ENTER 13

#define ESC 27
#define PAGE_UP 73
#define PAGE_DOWN 81
#define END 79
#define HOME 71

#define KEY_LEFT 75
#define KEY_UP 72
#define KEY_RIGHT 77
#define KEY_DOWN 80

#define MAX_BUFFER 5

#include <vector>
#include "input/boundary.h"
#include "common/types.h"

static Boundary<int> result_limits(0, 536870911);
static const byte ACTUAL_MAX = MAX_BUFFER + 2;

char Select(char cancel, char ok);
char Select(std::vector<char> targets);
char Next();
char Next(char target);
char Await(char (*program)(), char target);
void Await(bool (*program)());

template<class TYPE>
char Await(TYPE* instance, char (TYPE::*program)(), char target) {
    char code;
    do {
        code = ((instance)->*(program))();
    }
    while (code != target);
    return code;
}

#endif
