#include "task/forms/defaults/cui/markdown/floating/main.h"

Screen ArrayPanel(Markdown m) {
    byte margin = 1, left = 2;
    float ratio = 0.33f;

    m.Flatten(X, 4, 0.5)->Flatten(Y, 14, 0.78);
    m.Top(Y)->Margin(Y, margin);
    m.Top(X)->Margin(X, left)->Page();
    m.Bot(X)->Relate(X, ratio)->Page();
    m.Bot(X)->Margin(X, -margin)->Page();
    Screen result = m.Form()->Result();
    result.back->Rows.Split(0.5f);
    result.back->Columns.Split(0.22f);
    m.Clear();
    return result;
}
