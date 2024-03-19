#include "screen/interaction/lifetime/external.h"

void Await(bool (*program)()) {
    bool exit;
    do { exit = program(); } while (!exit);
}

char Await(char (*program)(), char target) {
    char code;
    
    do {
        code = program();
    }
    while (code != target);

    return code;
}
