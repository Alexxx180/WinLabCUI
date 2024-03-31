#include "task/forms/defaults/cui/screens/templates/footer.h"

#include "task/forms/defaults/cui/screens/templates/common.h"
#include "screen/interaction/interaction.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

char Footer()
{
    out->back.current->Columns.Set(0);
    out->back.current->Rows.Set(0);

    ProgramMessage("program_finished");

    out->Target(FOOT)->Form(0);
    out->Line(0)->Move();
    out->Clip("status_anykey");

    char code = Next();
    ClearScreen();

    out->Target(MAIN);
    return code;
}
