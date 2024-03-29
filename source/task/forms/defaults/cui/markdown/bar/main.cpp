#include "task/forms/defaults/cui/markdown/bar/main.h"

#include "screen/drawing/characters.h"

Corners DefaultBar() {
    Corners bar;
    bar.Standing = { UNDERSCORE, QUOTE1 };
    bar.Lying = { PIPE, DOT };

    bar.Vertical = { PIPE, PIPE };
    bar.Horizontal = { UNDERSCORE, OVERSCORE };

    Angles blank = { SPACE, SPACE };
    bar.Top = blank;
    bar.Bottom = blank;
    return bar;
}

Bar MainProgressBar(Markdown* m) {
    Corners edges = DefaultBar();
    Bar progress = m->ProgressBar(); 
    progress.SetSymbols(&edges);
    progress.Vertical(false);
    return progress;
}
