#include "task/structure/output/sort/header.h"

#include "screen/matrix/tools.h"
#include "task/structure/process/sort/utils/efficiency.h"

void SortHeader() {
    out->Page(0)->Span(2)->Size(2);
    out->Line(0)->Move()->Clip("output_source_array");
    out->Line(1)->Move()->Clip("output_sorted_array");
    out->Line(3)->Move()->Clear()->Move()->Span(1);
    out->Clip("sort_permutations");
    out->Text(L": ", permutations, ", ");
    out->Clip("sort_comparisons");
    out->Text(L": ", comparisons);
}
