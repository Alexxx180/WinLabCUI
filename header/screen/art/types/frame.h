#ifndef SCREEN_ART_MATRIX_TYPES
#define SCREEN_ART_MATRIX_TYPES

struct Edges {
    wchar_t left, center, right;
};

struct Angles {
    wchar_t left, right;
};

struct Frame {
    Edges horizontal, vertical;
    Angles top, bottom;
    wchar_t cross;
};

#endif
