#include "task/structure/output/individual/max.h"

#include "screen/matrix/tools.h"

void MaxHeader(char size, char T) {
	const wchar_t* no = L"%2i";

    out->Jump(3)->Move();
	pen->Clip("individual_source_data");
	pen->Text(L": N = ")->FText(no, size);
    pen->Text(L", T = ")->FText(no, T);
}

void MaxResult(char T) {
	out->Jump(2)->Move();
    pen->Clip("individual_max_element")->FText(L": %2i", T);
}
