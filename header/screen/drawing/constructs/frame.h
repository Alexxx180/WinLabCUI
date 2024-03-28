#ifndef SCREEN_DRAWING_CONSTRUCTS_FRAME
#define SCREEN_DRAWING_CONSTRUCTS_FRAME

#include "screen/drawing/constructs/outlines/edges.h"
#include "screen/drawing/constructs/outlines/angles.h"
#include "screen/drawing/characters.h"

struct Frame {
    Edges horizontal, vertical;
    Angles top, bottom;
    wchar_t cross;
};

static Frame InitFormEdges() {
	Edges horizontal = { 
		PIPE_FACED_LEFT, PIPE_HORIZONTAL, PIPE_FACED_RIGHT
	};
	Edges vertical = {
		PIPE_FACED_DOWN, PIPE_VERTICAL, PIPE_FACED_UP
	};
	Angles top = { ANGLE_TOP_LEFT, ANGLE_TOP_RIGHT };
	Angles bottom = { ANGLE_BOTTOM_LEFT, ANGLE_BOTTOM_RIGHT };
	return { horizontal, vertical, top, bottom, cross };
}

static Frame form_edges = InitFormEdges();

#endif
