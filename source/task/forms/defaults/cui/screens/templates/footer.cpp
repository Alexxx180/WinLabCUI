#include "task/forms/defaults/cui/screens/templates/footer.h"

#include "task/forms/defaults/cui/screens/templates/common.h"
#include "screen/interaction/interaction.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

char Footer()
{
    back->Columns.Set(0);
    back->Rows.Set(0);

    ProgramMessage("program_finished");

    layer->Target(FOOT);
    out->Form(0)->Line(0);
    pen->Clip("status_anykey");
    char code = Next();
    ClearScreen();

    layer->Target(MAIN);

    return code;
}
