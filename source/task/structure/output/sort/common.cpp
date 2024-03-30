#include "task/structure/output/sort/common.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void SortCommon() {
    layer->Target(FOOT);
    pen->Clip("status_forward");

    layer->Target(MAIN);
    out->Form(0)->Page(0)->Span(4);
    out->Line(0)->Size(2);
    out->Move()->Clear()->Move();
    pen->Clip("input_header");
    out->Span(1);
}
