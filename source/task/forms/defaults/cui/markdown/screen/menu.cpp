#include "task/forms/markdown/menu.h"
#include "screen/matrix/tools/markdown.h"
#include "screen/controls/matrix/screen.h"

Screen MenuPanel(Markdown* m) {
    byte offset = 1, size = 2, margin = 3;
    float ratio = 0.33;
    m->Shift(Y, { offset, size });
    m->Top(Y)->Margin(Y, offset);
    m->Top(X)->Margin(X, margin)->Page();
    m->Bot(X)->Relate(X, ratio)->Page();
    m->Bot(X)->Margin(X, -margin)->Page();
    Screen result = m->Form()->Result();
    m->Clear();
	return result;
}
