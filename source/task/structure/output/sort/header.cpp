#include "task/structure/output/sort/header.h"

#include "screen/matrix/tools.h"

void SortHeader() {
    out->Page(0)->Span(1)->Size(2);
    out->Line(0)->Move()->Clip("output_source_array");
    out->Line(1)->Move()->Clip("output_sorted_array");
}
