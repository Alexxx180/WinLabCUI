#include "task/structure/program.h"

#include "common/codes.h"
#include "screen/interaction/controller/keyboard.h"
#include "task/forms/defaults/cui/screens/templates/footer.h"
#include "task/forms/defaults/cui/screens/templates/header.h"
#include "task/structure/input/tasks.h"

int Program() {
    char code = Header();
    if (code == ENTER)
        Input();
    code = Footer();
    return OK;
}
