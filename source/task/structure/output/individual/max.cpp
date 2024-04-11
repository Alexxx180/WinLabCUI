#include "task/structure/output/individual/max.h"

#include "common/texts/format.h"
#include "screen/matrix/tools.h"

void MaxHeader(char size, char T) {
    out->Jump(3)->Move();
	out->Clip("individual_source_data");
	out->Text(L": N = ")->FText(NO2, size);
    out->Text(L", T = ")->FText(NO2, T);
}

void MaxResult(char T) {
	out->Jump(2)->Move();
    out->Clip("individual_max_element");
    out->Text(L": ")->FText(NO2, T);
}
