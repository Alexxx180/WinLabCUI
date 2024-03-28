#include "task/forms/markdown.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"
#include "screen/matrix/tools/markdown.h"
#include "screen/matrix/types/point.h"

#include "task/forms/defaults/cui/markdown/screen/main.h"
#include "task/forms/defaults/cui/markdown/screen/foot.h"
#include "task/forms/defaults/cui/markdown/screen/menu.h"
#include "task/forms/defaults/cui/markdown/floating/menu.h"

void ApplyMarkdown() {
    Point base = { 2, 2 };
    Point size = { 78, 20 };

    Screen context;
    Markdown m;

    context = MainPanel(&m, { base, size });
    layers[SCREEN].Add(&context);

    context = ArrayPanel({ base, size });
    layers[FLOATING].Add(&context);

    context = StatusBar(&m);
    layers[SCREEN].Add(&context);

    context = TableControls(m);
    layers[FLOATING].Add(&context);

    context = MenuPanel(&m);
    layers[SCREEN].Add(&context);
}
