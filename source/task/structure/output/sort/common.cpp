#include "task/structure/output/sort/common.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void SortCommon() {
    out->Target(FOOT)->Move()->Clear()->Move();
    out->Clip("status_forward");

    out->Target(MAIN);
    out->Form(0)->Page(0)->Size(2)->Line(0);
    out->Move()->Span(4)->Clear()->Span(1);
    out->Move()->Clip("input_header");
}
