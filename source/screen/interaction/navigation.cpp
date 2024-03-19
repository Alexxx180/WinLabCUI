#include "screen/interaction/navigation.h"

char Navigation :: Action() { return -1; }
void Navigation :: Previous() {}
void Navigation :: Next() {}
void Navigation :: Climb() {}
void Navigation :: Slide() {}
void Navigation :: First() {}
void Navigation :: Last() {}

short Navigation :: Choice() { return Action(); }

char Navigation :: Query() {
    char code = Input();

    switch (code) {
        case ENTER:
            code = Action();
            break;
        case KEY_UP:
        case KEY_LEFT:
            Previous();
            break;
        case KEY_DOWN:
        case KEY_RIGHT:
            Next();
            break;
        case HOME:
            First();
            break;
        case END:
            Last();
            break;
        case PAGE_UP:
            Climb();
            break;
        case PAGE_DOWN:
            Slide();
            break;
        default:
            break;
    }

    return code;
}
