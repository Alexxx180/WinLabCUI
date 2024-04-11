#include "task/forms/defaults/cui/markdown/floating/foot.h"

#include "screen/interaction/interaction.h"

Screen TableControls(Markdown* m) {
    byte margin = 3, columns = 3;
    float ratio = 0.33f;
    m->Top()->Margin(Y, 1)->Margin(X, margin)->Page();

    for (byte c = 1; c <= columns; c++) {
        m->Bot(X);
        m->Relate(X, c * ratio);
        m->Margin(X, margin)->Page();
    }

    Screen result = m->Form()->Result();
    m->Clear();
    return result;
}

