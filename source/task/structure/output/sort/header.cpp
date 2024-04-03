#include "task/structure/output/sort/header.h"

#include "screen/matrix/tools.h"

void SortHeader() {
    out->Size(2)->Span(1);
    out->Move();
    out->Clip("output_source_array");
    out->Line()->Move();
    out->Clip("output_sorted_array");
}
