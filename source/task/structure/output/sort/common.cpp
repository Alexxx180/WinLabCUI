#include "task/structure/output/sort/common.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void SortCommon() {
    out->Target(FOOT)->Move();
    out->Clip("status_forward");

    out->Target(MAIN);
    out->Form(0)->Page(0)->Size(2);
    out->Line(0)->Move();
    out->Span(4)->Clear();
    out->Span(1)->Move();
    out->Clip("input_header");
    out->Span(1);
}
