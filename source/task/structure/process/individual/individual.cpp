#include "task/structure/process/individual/individual.h"

#include "task/structure/process/individual/max.h"
#include "task/structure/process/individual/interval.h"
#include "screen/matrix/tools.h"

void StartIndividual() {
    out->Target(MAIN);
    out->Line(0)->Size(1);
    out->Page(0)->Move();
    out->Clip("individual_arrays");

    IntervalSum();
    MaxElement();

    out->Target(MENU)->Move();
}
