#include "screen/matrix/types/range.h"

Range Range :: SwapXY() {
    return {
        { P1.X, P2.X },
        { P1.Y, P2.Y }
    };
}

Range Range :: Swap() {
    return { P2, P1 };
}

Range Range :: SwapSizes() {
    return { P1.Swap(), P2.Swap() };
}

byte Range :: SumX() {
    return P1.X + P2.X;
}

byte Range :: SumY() {
    return P1.Y + P2.Y;
}
