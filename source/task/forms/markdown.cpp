#include "task/forms/markdown.h"

#include "screen/art/types/layers.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/markdown.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"
#include "task/forms/markdown/content.h"
#include "task/forms/markdown/foot.h"
#include "task/forms/markdown/menu.h"

void Resize() {
    Point base = { 2, 2 };
    Point size = { 78, 20 };
    Range content = { base, size };

    Markdown m;
    MainPanel(&m, &content);
    StatusBar(&m);
    MenuPanel(&m);
    Pen::ink().Target(MAIN);
}
