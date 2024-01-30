#include "task/markdown.h"

#include <windows.h>

#include <vector>

#include "screen/art/controls/layers.h"
#include "task/markdown/main.h"
#include "task/markdown/foot.h"
#include "common/types.h"
#include "output/format/pen.h"

void Resize() {
    Range content = { { 2,  2 }, { 78, 20 } };

    MainMarkdown(&content);
    FootMarkdown(&content);
    Pen::ink().Target(MAIN);
}
