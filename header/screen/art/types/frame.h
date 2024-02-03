#ifndef SCREEN_ART_TYPES_FRAME
#define SCREEN_ART_TYPES_FRAME

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
