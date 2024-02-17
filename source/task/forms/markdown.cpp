#include "task/forms/markdown.h"

#include "screen/art/types/layers.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/markdown.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"
#include "task/forms/markdown/main.h"
#include "task/forms/markdown/foot.h"
#include "task/forms/markdown/menu.h"

void Resize() {
    Markdown m;
    Range content = { { 2,  2 }, { 78, 20 } };

    MainMarkdown(&m, &content);
    FootMarkdown(&m);
    MenuMarkdown(&m);
    Pen::ink().Target(MAIN);
}
