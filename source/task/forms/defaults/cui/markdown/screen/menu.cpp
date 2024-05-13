#include "task/forms/defaults/cui/markdown/screen/menu.h"

Screen MenuPanel(Markdown* m) {
    byte offset = 1, size = 2, margin = 3;
    m->Shift(Y, offset, size);
    m->Top(Y)->Margin(Y, offset);
    m->Top(X)->Margin(X, margin)->Page();
    m->Split(X, 0.2);
    m->Bot(X)->Margin(X, -margin)->Page();
    Screen result = m->Form()->Result();
    m->Clear();
	return result;
}
