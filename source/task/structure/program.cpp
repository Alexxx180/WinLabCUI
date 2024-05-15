#include "task/structure/program.h"

#include "common/codes.h"
#include "screen/interaction/controller/keyboard.h"
#include "task/forms/defaults/cui/screens/templates/header.h"
#include "task/structure/input/tasks.h"

int Program() {
    if (Header() == ENTER) Input();
    return OK;
}
