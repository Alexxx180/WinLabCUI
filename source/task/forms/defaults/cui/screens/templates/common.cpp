#include "task/forms/defaults/cui/screens/templates/common.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void ProgramMessage(std::string description) {
    ClearScreen();

    out->Target(MAIN)->ShowBack();
    out->Form(0)->Page(0)->Size(3);

    out->Line(0)->Move();
    out->Clip("program_header");
    out->Line()->Move();
    out->Clip("program_name");
    out->Line()->Move();
    out->Clip(description);
}
