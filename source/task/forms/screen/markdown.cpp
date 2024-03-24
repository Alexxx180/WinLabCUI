#include "task/forms/markdown.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"
#include "screen/matrix/tools/markdown.h"
#include "screen/matrix/types/point.h"
#include "task/forms/markdown/content.h"
#include "task/forms/markdown/foot.h"
#include "task/forms/markdown/menu.h"

void ScreenMarkdown() {
    Point base = { 2, 2 };
    Point size = { 78, 20 };

    Screen context;
    Markdown m;

    context = MainPanel(&m, { base, size });
    layers[SCREEN].Add(&context);

    context = ArrayPanel();
    layers[FLOATING].Add(&context);

    context = StatusBar(&m);
    layers[SCREEN].Add(&context);
    layers[FLOATING].Add(&context);

    context = MenuPanel(&m);
    layers[SCREEN].Add(&context);
}
