#include "task/structure/process/individual/individual.h"

#include "task/structure/process/individual/max.h"
#include "task/structure/process/individual/interval.h"
#include "screen/matrix/tools.h"

void StartIndividual() {
    layer->Target(MAIN);
    out->Page(0)->Size(1)->Line(0)->Move();
    pen->Clip("individual_arrays");

    IntervalSum();
    MaxElement();

    layer->Target(MENU);
    out->Move();
}
