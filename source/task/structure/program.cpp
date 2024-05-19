#include "task/structure/program.h"

#include "common/codes.h"
#include "screen/interaction/controller/keyboard.h"
#include "task/forms/defaults/cui/screens/templates/header.h"
#include "task/structure/input/tasks.h"
#include "screen/matrix/tools.h"

int Program() {
    if (Header() == ENTER)
        Input();
    else
        ClearScreen();

    return OK;
}
