#include "task/forms/screens/header.h"

#include "task/forms/screens/common.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/keyboard.h"

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
