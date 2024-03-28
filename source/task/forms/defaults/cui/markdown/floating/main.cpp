#include "task/forms/defaults/cui/markdown/floating/main.h"

#include "screen/matrix/tools/markdown.h"

Screen ArrayPanel(Markdown m, byte width) {
    byte margin = 1, left = 2;
    float ratio = 0.33f;
    m.Flatten(X, 4, 0.5)->Flatten(Y, 18, 0.78);
    m.Top(Y)->Margin(Y, margin);
    m.Top(X)->Margin(X, left)->Page();
    m.Bot(X)->Relate(X, ratio)->Page();
    m.Bot(X)->Margin(X, -margin)->Page();
    Screen result = m->Form()->Result();
    m.Clear();
    return result;
}
