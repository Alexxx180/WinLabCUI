#include "task/forms/markdown/foot.h"

#include "screen/matrix/markdown.h"
#include "screen/matrix/types/point.h"

void FootMarkdown(Markdown* m) {
    unsigned char margin = 3, grid = 2;
	float ratio = 0.33f;

    Point offset = { 1, 3 };
    m->ShiftY(offset);
    // Alert panel
    m->P2()->PinY()->MarginY(-1);
	m->P1()->PinX()->MarginX(margin)->Page();
    m->P2()->PinX()->MarginX(-margin)->Page()->Form();
    // Table controls
    m->P1()->PinY()->PinX()->Page();
	for (unsigned char column = 1; column <= grid; column++) {
	    m->P2()->PinX()->RatioX(column * ratio);
		m->MarginX(margin)->Page();
	}
    m->Form()->Screen();
}

