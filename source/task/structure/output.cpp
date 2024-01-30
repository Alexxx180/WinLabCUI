#include "task/structure/output.h"

#include <string>

#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "common/types.h"
#include "common/texts/common.h"
#include "output/format/pen.h"

void OutputHeader(Answer* task) {
    short align = 3;

    Pen::ink().screen->Form(1)->Page(0)->Line(0);
    Pen::ink().Quote(L"output_header");
    Pen::ink().screen->Line();
    Pen::ink().Quote(L"output_x_n")->Text(task->X, L" = ");
    Pen::ink().screen->Line();
    Pen::ink().Quote(L"output_f_arctg");
    Pen::ink().screen->Line();

    Pen::ink().Quote(L"output_c_atan");
    Pen::ink().screen->Page(align)->Move();
    Pen::ink().Text(task->F.result.X, L" = ");
    Pen::ink().Text(task->F.legacy, L" : ");
    Pen::ink().screen->Page(0)->Line();

    Pen::ink().Quote(L"output_f_recursion");
    Pen::ink().screen->Page(align)->Move();
    Pen::ink().Text(task->F.result.Y, L" = ");
    Pen::ink().Text(task->F.recursion, L" : ");
    Pen::ink().screen->Page(0)->Line();

    Pen::ink().Quote(L"output_f_iteration");
    Pen::ink().screen->Page(align)->Move();
    Pen::ink().Text(task->F.result.Z, L" = ");
    Pen::ink().Text(task->F.recursion, L" : ");
    Pen::ink().screen->Page(0)->Line();
}

char Output(Answer* task) {
    OutputHeader(task);
    Pen::ink().Target(FOOT);
    Pen::ink().Quote("status_exit");
    Pen::ink().Target(MAIN);
    return Select(ESC, ENTER);
}
