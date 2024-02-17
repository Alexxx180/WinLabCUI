#include "task/structure/output/sort/common.h"

#include "screen/art/controls/layers.h"
#include "screen/matrix/pen.h"

void OutputCommonHeader() {
    Pen::ink().Target(FOOT)->Quote("status_forward");
    Pen::ink().Target(MAIN);
    Pen::ink().screen->Form(0)->Page(0)->Span(4)->Size(2)->Line(0);
    Pen::ink().Quote("input_header")->screen->Span(1);
}

void OutputArraySortHead() {
    Pen::ink().screen.Span(1)->Form(1)->Size(2);
    Pen::ink().Quote("output_source_array");

    Pen::ink().screen.Line();
    Pen::ink().Quote("output_sorted_array");
}
