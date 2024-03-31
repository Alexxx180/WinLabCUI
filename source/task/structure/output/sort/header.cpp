#include "task/structure/output/sort/header.h"

#include "screen/matrix/tools.h"

void SortHeader() {
    out->Form(1)->Size(2);
    out->Span(1)->Move();
    out->Clip("output_source_array");
    out->Line()->Move();
    out->Clip("output_sorted_array");
}
