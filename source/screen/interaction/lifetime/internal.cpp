#include "screen/interaction/lifetime/internal.h"

template<class TYPE>
char Await(TYPE* instance, char (TYPE::*program)(), char target) {
    char code;

    do {
        code = ((instance)->*(program))();
    }
    while (code != target);

    return code;
}

template<class TYPE>
char Await(TYPE* instance, char (TYPE::&program)(), char target) {
    char code;

    do {
        code = ((instance)->*(program))();
    }
    while (code != target);

    return code;
}
