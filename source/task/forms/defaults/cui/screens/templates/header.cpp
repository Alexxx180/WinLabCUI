#include "task/forms/defaults/cui/screens/templates/header.h"

#include "task/forms/defaults/cui/screens/templates/common.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

char Header()
{
    ProgramMessage("program_description");

    out->Line()->Move();
    out->Clip("program_author");

    out->Target(FOOT)->ShowBack()->Move();
    out->Clip("status_exit")->Span(1);

    char code = Select(ESC, ENTER);

    out->Target(MAIN);
    return code;
}
