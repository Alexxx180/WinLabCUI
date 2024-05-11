#include "task/forms/defaults/cui/markdown/screen/main.h"

#include "input/feedback/limiting/buffer.h"

Screen MainPanel(Markdown* m, Range content) {
    byte margin = 3;
    m->Base(&content)->Origin();
    m->Top(Y)->Margin(Y, margin);
    m->Top(X)->Margin(X, margin)->Page();
    m->Bot(X)->Relate(X, 0.2)->Page();
    m->Bot(X)->Relate(X, 0.5)->Page();
    Screen result = m->Form()->Result();
    m->Clear();
    return result;
}
