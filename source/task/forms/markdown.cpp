#include "task/markdown.h"

#include "screen/art/types/layers.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"
#include "task/forms/markdown/main.h"
#include "task/forms/markdown/foot.h"
#include "task/forms/markdown/menu.h"

void Resize() {
    Range content = { { 2,  2 }, { 78, 20 } };

    MainMarkdown(&content);
    FootMarkdown(&content, content.P2.Y);
    MenuMarkdown(&content, content.P2.Y);
    Pen::ink().Target(MAIN);
}
