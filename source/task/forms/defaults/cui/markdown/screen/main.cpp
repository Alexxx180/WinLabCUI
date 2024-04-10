#include "task/forms/defaults/cui/markdown/screen/main.h"

#include "input/feedback/limiting/buffer.h"

Screen MainPanel(Markdown* m, Range content) {
    byte margin = 3;
    float ratio = 0.5f;
    m->Base(&content)->Origin();
    m->Top(Y)->Margin(Y, margin);
    m->Top(X)->Margin(X, margin)->Page();
    m->Bot(X)->Relate(X, ratio)->Margin(X, -MAX_BUFFER)->Page();
    m->Bot(X)->Relate(X, ratio)->Page();
    m->Bot(X)->Relate(X, ratio)->Margin(X, margin)->Page();
    m->Bot(X)->Margin(X, -MAX_BUFFER - margin)->Page();
    m->Bot(X)->Margin(X, -margin)->Page();
    Screen result = m->Form()->Result();
    m->Clear();
    return result;
}
