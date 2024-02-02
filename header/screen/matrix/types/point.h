#ifndef SCREEN_MATRIX_TYPES
#define SCREEN_MATRIX_TYPES

struct Point {
    unsigned char X, Y;

    void Swap() {
        unsigned char placeholder = X;
        X = Y;
        Y = placeholder;
    }
};

#endif
