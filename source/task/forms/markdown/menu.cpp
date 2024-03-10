#include "task/forms/markdown/menu.h"

#include "screen/matrix/markdown.h"
#include "screen/matrix/types/point.h"

void MenuMarkdown(Markdown* m) {
    unsigned char margin = 3;

    Point panelOffset = { 1, 2 };
    m->ShiftY(panelOffset);
    // Menu panel
    m->P1()->PinY()->MarginY(1);
    m->P1()->PinX()->MarginX(margin)->Page();
    m->P2()->PinX()->RatioX(0.33)->Page();
    m->P2()->PinX()->MarginX(-margin)->Page();
	m->Form()->Screen();
}
