#include "task/forms/defaults/cui/screens/templates/header.h"

#include "task/forms/defaults/cui/screens/templates/common.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

char Header()
{
    ProgramMessage("program_description");
    out->Line();
    pen->Clip("program_author");
    
    layer->Target(FOOT);
    pen->Clip("status_exit");
    out->Span(1);
    char code = Select(ESC, ENTER);

    layer->Target(MAIN);
    return code;
}
