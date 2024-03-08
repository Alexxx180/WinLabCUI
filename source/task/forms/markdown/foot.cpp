#include "task/forms/markdown/foot.h"

#include "screen/matrix/markdown.h"
#include "screen/matrix/types/point.h"

void FootMarkdown(Markdown* m) {
    unsigned char p = 3;
    float third = 1 / 3;

    Point offset = { 1, 3 };
    m->ShiftY(offset);
    // Alert panel
    m->P2()->PinY()->MarginY(-1);
	m->P1()->PinX()->MarginX(p)->Page();
    m->P2()->PinX()->MarginX(-p)->Page()->Form();
    // Table controls
    m->P1()->PinY()->PinX()->Page();
    m->P2()->PinX()->RatioX(third)->MarginX(p)->Page();
    m->P2()->PinX()->RatioX(third * 2)->MarginX(p)->Page();
    m->Form()->Screen();
}

