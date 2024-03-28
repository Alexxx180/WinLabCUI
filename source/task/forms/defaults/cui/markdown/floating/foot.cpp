#include "task/forms/defaults/cui/markdown/floating/foot.h"

#include "screen/matrix/tools/markdown.h"

// Table controls info
Screen TableControls(Markdown m) {
    byte margin = 3, columns = 2;
    float ratio = 0.33f;
    m.Top()->Page();
    for (byte c = 1; c <= columns; c++) {
        m.Top(X);
        m.Relate(X, c * ratio);
        m.Margin(X, margin)->Page();
    }
    Screen result = m->Form()->Result();
    m->Clear();
    return result;
}

