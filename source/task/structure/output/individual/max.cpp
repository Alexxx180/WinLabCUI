#include "task/structure/output/individual/max.h"

#include "screen/matrix/tools.h"

void MaxHeader(char size, char T) {
	const wchar_t* no = L"%2i";

    out->Jump(3)->Move();
	out->Clip("individual_source_data");
	out->Text(L": N = ")->FText(no, size);
    out->Text(L", T = ")->FText(no, T);
}

void MaxResult(char T) {
	out->Jump(2)->Move();
    out->Clip("individual_max_element");
    out->FText(L": %2i", T);
}
