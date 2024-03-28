#include "task/forms/markdown.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"
#include "screen/matrix/tools/markdown.h"
#include "screen/matrix/types/point.h"

#include "task/forms/defaults/cui/markdown/screen/main.h"
#include "task/forms/defaults/cui/markdown/screen/foot.h"
#include "task/forms/defaults/cui/markdown/screen/menu.h"
#include "task/forms/defaults/cui/markdown/floating/menu.h"
//#include "task/forms/defaults/cui/markdown/bar/main.h"

void ApplyMarkdown() {
    Point base = { 2, 2 };
    Point size = { 78, 20 };

    Screen context;
    Markdown m;

    context = MainPanel(&m, { base, size });
    layers[SCREEN].Add(&context);

    context = ArrayPanel(m);
    layers[FLOATING].Add(&context);

    context = StatusBar(&m);
    layers[SCREEN].Add(&context);

    context = TableControls(&m);
    layers[FLOATING].Add(&context);

    context = MenuPanel(&m);
    layers[SCREEN].Add(&context);

    // Bar progress = MainProgressBar(&m);
    // layers[SCREEN].status.Add(&progress);
}
