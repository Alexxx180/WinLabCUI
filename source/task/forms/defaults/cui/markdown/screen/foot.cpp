#include "task/forms/defaults/cui/markdown/floating/foot.h"

Screen StatusBar(Markdown* m) {
    byte offset = 1, size = 3, margin = 3;
    m->Shift(Y, offset, size);
    m->Bot(Y)->Margin(Y, -offset);
    m->Top(X)->Margin(X, margin)->Page();
    m->Bot(X)->Margin(X, -margin)->Page();
    Screen result = m->Form()->Result();
    m->Clear();
    return result;
}
