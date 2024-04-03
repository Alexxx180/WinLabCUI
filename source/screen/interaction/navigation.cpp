#include "screen/interaction/navigation.h"
#include "screen/interaction/controller/keyboard.h"

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
