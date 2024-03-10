#include "task/forms/markdown/content.h"

#include "screen/interaction.h"
#include "screen/matrix/markdown.h"
#include "screen/matrix/types/range.h"
#include "task/forms/markdown/main/table.h"
#include "task/forms/markdown/main/bar.h"

void MainMarkdown(Markdown* m, Range* content) {
    unsigned char margin = 3, input = MAX_BUFFER;
    float half = 0.5f, third = 0.33f;

    TableMarkdown(content);
    BarMarkdown(content);

    m->Base(content)->Origin()->P1();
    // Main panel
    m->PinY()->MarginY(margin);
	m->PinX()->MarginX(margin)->Page();
    m->P2()->PinX()->RatioX(half)->MarginX(-input)->Page();
    m->P2()->PinX()->RatioX(half)->Page();
    m->P2()->PinX()->RatioX(half)->MarginX(margin)->Page();
    m->P2()->PinX()->MarginX(-input)->MarginX(-margin)->Page();
    m->P2()->PinX()->MarginX(-margin)->Page();
    m->Form();
    // Table frame
    m->P2()->PinY()->MarginY(-margin)->MarginY(-1);
    m->P1()->PinX()->MarginX(margin)->MarginX(2)->Page();
    m->P2()->PinX()->RatioX(third)->Page();
    m->P2()->PinX()->MarginX(-margin)->MarginX(-1)->Page();
    m->Form()->Screen();
}
