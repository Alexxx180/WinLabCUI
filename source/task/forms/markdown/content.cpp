#include "task/forms/markdown/content.h"

#include "screen/interaction.h"
#include "screen/matrix/markdown.h"
#include "screen/matrix/types/range.h"
#include "task/forms/markdown/main/table.h"
#include "task/forms/markdown/main/bar.h"

void MainMarkdown(Markdown* m, Range* content) {
    unsigned char p = 3, i = MAX_BUFFER;
    float half = 0.5f, third = 1 / 3;

    TableMarkdown(content);
    BarMarkdown(content);

    m->Base(content)->Origin();
    // Main panel
    m->P1()->PinY()->MarginY(p)->PinX()->MarginX(p)->Page();
    m->P2()->PinX()->RatioX(half)->MarginX(-i)->Page();
    m->P2()->PinX()->RatioX(half)->Page();
    m->P2()->PinX()->RatioX(half)->MarginX(p)->Page();
    m->P2()->PinX()->MarginX(-i)->MarginX(-p)->Page();
    m->P2()->PinX()->MarginX(-p)->Page();
    m->Form();
    // Table frame
    m->P2()->PinY()->MarginY(-p)->MarginY(-1);
    m->P1()->PinX()->MarginX(p)->MarginX(2)->Page();
    m->P2()->PinX()->RatioX(third)->Page();
    m->P2()->PinX()->MarginX(-p)->MarginX(-1)->Page();
    m->Form()->Screen();
}
