#include "task/structure/output/individual/max.h"

#include "screen/matrix/tools.h"

const wchar_t* no = L"%2i";

void MaxHeader(char size, char T) {
    out->Jump(3)->Move();
	out->Clip("individual_source_data");
	out->Text(L": N = ")->FText(no, size);
    out->Text(L", T = ")->FText(no, T);
}

void MaxResult(char T) {
	out->Jump(2)->Move();
    out->Clip("individual_max_element");
    out->Text(L": ")->FText(no, T);
}
