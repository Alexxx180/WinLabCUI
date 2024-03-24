#ifndef SCREEN_DRAWING_CONSTRUCTS_OUTLINES_ANGLES
#define SCREEN_DRAWING_CONSTRUCTS_OUTLINES_ANGLES

struct Angles {
    wchar_t left, right;
	Angles Swap() { return { right, left }; }
};

#endif
