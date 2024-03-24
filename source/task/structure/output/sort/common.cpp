#include "task/structure/output/sort/common.h"

#include "screen/drawing/types/layers.h"
#include "screen/matrix/tools.h"

void OutputCommonHeader() {
    layer->Target(FOOT);
    pen->Clip("status_forward");

    layer->Target(MAIN);
    out->Form(0)->Page(0)->Line(0)->Span(4)->Size(2);
    pen->Clip("input_header");
    out->Span(1);
}

void OutputArraySortHead() {
    out->Span(1)->Form(1)->Size(2);
    pen->Quote("output_source_array");
    out->Line();
    pen->Quote("output_sorted_array");
}
