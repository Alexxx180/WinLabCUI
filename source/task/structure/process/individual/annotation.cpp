#include "screen/matrix/tools.h"

void IndividualCaption() {
    out->Target(MAIN);
    out->Line(0)->Size(1);
    out->Page(0)->Move();
    out->Clip("individual_arrays");
}

void IndividualCursor() {
    out->Target(MENU)->Move();
}
