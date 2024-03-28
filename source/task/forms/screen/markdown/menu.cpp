#include "task/forms/markdown/menu.h"
#include "screen/matrix/tools/markdown.h"
#include "screen/controls/matrix/screen.h"

Screen MenuPanel(Markdown* m) {
    byte offset = 1, size = 2, margin = 3;

    m->Shift(Y, { offset, size });
    m->Top()->Pin(Y)->Margin(Y, 1);
    m->Top()->Pin(X)->Margin(X, margin)->Page();
    m->Bot()->Pin(X)->Relate(X, 0.33)->Page();
    m->Bot()->Pin(X)->Margin(X, -margin)->Page();
	return m->Form()->Result();
}
