#include "task/forms/themes.h"

#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void ProgramMessage(std::string description) {
    ClearScreen();
    layer->Target(FOOT);
    back->Show();
    layer->Target(MAIN);
    back->Show();
    out->Form(0)->Page(0)->Line(0)->Size(3);
    pen->Clip("program_header")
    out->Line();
    pen->Clip("program_name")
    out->Line();
    pen->Clip(description);
}

char Header()
{
    ProgramMessage("program_description");
    out->Line();
    pen->Clip("program_author");
    layer->Target(FOOT);
    pen->Clip("status_exit");
    out->Span(1);
    pen->Target(MAIN);

    return Select(ESC, ENTER);
}

char Footer()
{
    back->Columns.Set(0);
    back->Rows.Set(0);

    ProgramMessage("program_finished");
    layer->Target(FOOT);
    out->Form(0)->Line(0);
    pen->Clip("status_anykey");
    layer->Target(MAIN);

    char code = Next();
    ClearScreen();

    return code;
}
