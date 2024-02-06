#ifndef SCREEN_MATRIX_TYPES_RANGE
#define SCREEN_MATRIX_TYPES_RANGE

#include "screen/matrix/types/point.h"

struct Range {
    Point P1, P2;

    Range SwapXY() {
        return {
            { this->P1.X, this->P2.X },
            { this->P1.Y, this->P2.Y }
        };
    }

    Range Swap() { return { this->P2, this->P1 }; };

    Range SwapSizes() {
        return {
            { this->P1.Y, this->P1.X },
            { this->P2.Y, this->P2.X }
        };
    }

    unsigned char SumX() { return this->P1.X + this->P2.X; }
    unsigned char SumY() { return this->P1.Y + this->P2.Y; }
};

#endif
