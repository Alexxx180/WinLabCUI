#include "task/forms/defaults/cui/screens/templates/common.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void ProgramMessage(std::string description) {
    ClearScreen();
    layer->Target(FOOT);
    back->Show();
    layer->Target(MAIN);
    back->Show();
    out->Form(0)->Page(0)->Line(0)->Size(3);
    pen->Clip("program_header");
    out->Line();
    pen->Clip("program_name");
    out->Line();
    pen->Clip(description);
}
