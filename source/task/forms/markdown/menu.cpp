#include "task/forms/markdown/menu.h"

#include "screen/matrix/markdown.h"
#include "screen/matrix/types/point.h"

void MenuMarkdown(Markdown* m) {
    unsigned char p = 3;
    float third = 1 / 3;

    Point offset = { 1, 2 };
    m->ShiftY(offset);
    // Menu panel
    m->P1()->PinY()->MarginY(1);
    m->P1()->PinX()->MarginX(p)->Page();
    m->P2()->PinX()->RatioX(third)->MarginX(p)->Page();
    m->P2()->PinX()->MarginX(-p)->Page()->Form()->Screen();
}
