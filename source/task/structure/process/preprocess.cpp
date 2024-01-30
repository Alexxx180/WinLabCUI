#include "common/types.h"
#include "common/texts/common.h"
#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "output/format/pen.h"

void ResultsOverflow() {
    Pen::ink().Target(FOOT)->Quote("status_anykey");
    Pen::ink().Target(MAIN)->Quote("input_results_overflow");
    Next();
}

void BigO(Vector2i* size, unsigned int count) {
    Pen::ink().Quote("input_count");
    Pen::ink().Text(L": X = ")->Text(size->X);
    Pen::ink().Text(L", Y = ")->Text(size->Y);
    Pen::ink().Text(L". O(X*Y) = ")->Text(count);
    Pen::ink().screen->Line();
}


bool Preprocess(Loop2* laps) {
    Vector2i size = laps->Size();
    unsigned int count = laps->count;

    Pen::ink().screen->Page(0)->Line();
    BigO(&size, count);
    Pen::ink().screen->Line();

    if (result_limits.Verify(count)) {
        ResultsOverflow();
        return true;
    }

    Pen::ink().Target(FOOT)->Quote("status_exit")->Target(MAIN);
    return Select(ESC, ENTER) == ESC;
}
