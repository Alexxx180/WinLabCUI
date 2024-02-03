#include "screen/themes.h"

#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "output/format/pen.h"

#include <conio.h>

void ProgramName() {
    Pen::ink().Reset();
    Pen::ink().Target(FOOT).screen->Show();
    Pen::ink().Target(MAIN).screen->Show();
    Pen::ink().screen->Form(0)->Page(0)->Line(0)->Size(3);
    Pen::ink().Quote("program_header")->screen->Line();
    Pen::ink().Quote("program_name")->screen->Line();
}

char Header()
{
    ProgramName();
    Pen::ink().Quote("program_description")->screen->Line();
    Pen::ink().Quote("program_author")->Target(FOOT);
    Pen::ink().Quote("status_exit")->screen->Span(1);
    Pen::ink().Target(MAIN);

    return Select(ESC, ENTER);
}

char Footer()
{
    short count = 0;
    Pen::ink().back->Columns.Set(count);
    Pen::ink().back->Rows.Set(count);

    ProgramName();
    Pen::ink().Quote("program_finished");

    Pen::ink().Target(FOOT)->screen->Form(0)->Line(0);
    Pen::ink().Quote("status_anykey")->Target(MAIN);

    char code = Next();
    Pen::ink().Reset();

    return code;
}
