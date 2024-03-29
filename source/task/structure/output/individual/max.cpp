#include "task/structure/output/individual/max.h"

#include "screen/matrix/tools.h"

void MaxHeader(char size, char T) {
	const wchar_t* no = L"%2i";

    out->Slide(3)->Move();
	pen->Clip("individual_source_data");
	pen->Text(": N = ")->FText(no, size);
    pen->Text(", T = ")->FText(no, T);
}

void MaxResult(char T) {
	out->Slide(2)->Move();
    pen->Clip("individual_max_element")->FText(L": %2i", T);
}
