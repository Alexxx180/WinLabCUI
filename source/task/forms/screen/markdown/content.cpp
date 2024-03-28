#include "task/forms/markdown/content.h"

#include "input/limiting/buffer.h"
#include "screen/interaction/interaction.h"
#include "screen/matrix/markdown.h"
#include "screen/matrix/types/range.h"
#include "task/forms/markdown/main/table.h"
#include "task/forms/markdown/main/bar.h"
#include "screen/controls/matrix/screen.h"

Screen MainPanel(Markdown* m, Range content) {
    byte margin = 3, input = MAX_BUFFER;
    float half = 0.5f, third = 0.33f;

    TableGrid(&content);
    MainProgressBar(&content);

    m->Base(&content)->Origin();
    // Main panel
    m->Top()->Pin(Y)->Margin(Y, margin)->Pin(X)->Margin(X, margin)->Page();
    m->Bot()->Pin(X)->Relate(X, half)->Margin(X, -input)->Page();
    m->Bot()->Pin(X)->Relate(X, half)->Page();
    m->Bot()->Pin(X)->Relate(X, half)->Margin(X, margin)->Page();
    m->Bot()->Pin(X)->Margin(X, -input - margin)->Page();
    m->Bot()->Pin(X)->Margin(X, -margin)->Page();
    m->Form();
    // Table frame
    m->Bot()->Pin(Y)->Margin(Y, -margin - 1);
    m->Top()->Pin(X)->Margin(X, margin + 2)->Page();
    m->Bot()->Pin(X)->Relate(X, third)->Page();
    m->Bot()->Pin(X)->Margin(X, -margin - 1)->Page();
    return m->Form()->Result();
}
