#include "task/structure/output/sort/header.h"

#include "screen/drawing/types/layers.h"
#include "screen/matrix/tools.h"

void SortHeader() {
    out->Span(1)->Form(1)->Size(2);
    pen->Clip("output_source_array");
    out->Line();
    pen->Clip("output_sorted_array");
}
