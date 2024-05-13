#include "task/forms/defaults/cui/screens/templates/header.h"

#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

char Header()
{
    ClearScreen();

    out->Target(MAIN)->ShowBack();
    out->Form(0)->Page(0)->Size(3);

    out->Line(0)->Move();
    out->Clip("program_header");
    out->Line()->Move();
    out->Clip("program_name");
    out->Jump(2)->Move();
    out->Clip("program_description");
    out->Line()->Move();
    out->Clip("program_labs");
    out->Line()->Move();
    out->Clip("program_processing");
    out->Line()->Move();
    out->Clip("program_language");
    out->Line()->Move();
    out->Clip("program_author");

    out->Target(FOOT)->ShowBack()->Move();
    out->Clip("status_exit")->Span(1);

    char code = Select(ESC, ENTER);

    out->Target(MAIN);
    return code;
}
