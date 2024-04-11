#include "screen/matrix/types/point.h"

Point Point :: Swap() {
    return { Y, X };
}

byte Point :: Sum() {
    return X + Y;
}

