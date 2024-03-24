#include "task/forms/markdown/foot.h"
#include "screen/matrix/tools/markdown.h"
#include "screen/controls/matrix/screen.h"

Screen StatusBar(Markdown* m) {
    byte offset = 1, size = 3, margin = 3;
    byte columns = 2;
    float ratio = 0.33f;

    m->Shift(Y, { offset, size });
    // Status messages string
    m->Bot()->Pin(Y)->Margin(Y, -1);
    m->Top()->Pin(X)->Margin(X, margin)->Page();
    m->Bot()->Pin(X)->Margin(X, -margin)->Page();
    m->Form();
    // Table controls info
    m->Top()->Pin(Y)->Pin(X)->Page();
    for (byte column = 1; column <= columns; column++) {
        m->Top()->Pin(X);
        m->Relate(X, column * ratio);
        m->Margin(X, margin)->Page();
    }
    return m->Form()->Screen();
}

