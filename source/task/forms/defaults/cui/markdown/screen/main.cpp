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
    float ratio = 0.5f;
    m->Base(&content)->Origin();
    m->Top(Y)->Margin(Y, margin);
    m->Top(X)->Margin(X, margin)->Page();
    m->Bot(X)->Relate(X, ratio)->Margin(X, -input)->Page();
    m->Bot(X)->Relate(X, ratio)->Page();
    m->Bot(X)->Relate(X, ratio)->Margin(X, margin)->Page();
    m->Bot(X)->Margin(X, -input - margin)->Page();
    m->Bot(X)->Margin(X, -margin)->Page();
    Screen result = m->Form()->Result();
    m->Clear();
    return result;
}
