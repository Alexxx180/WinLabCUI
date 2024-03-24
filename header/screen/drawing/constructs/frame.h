#ifndef SCREEN_DRAWING_CONSTRUCTS_FRAME
#define SCREEN_DRAWING_CONSTRUCTS_FRAME

#include "screen/drawing/constructs/outlines/edges.h"
#include "screen/drawing/constructs/outlines/angles.h"

struct Frame {
    Edges horizontal, vertical;
    Angles top, bottom;
    wchar_t cross;
};

static Frame InitFormEdges() {
	// pipes: ╠, ═, ╣
	wchar_t pipe_faced_left = 9568;
	wchar_t pipe_horizontal = 9552;
	wchar_t pipe_faced_right = 9571;
	// pipes: ╦, ║, ╩
	wchar_t pipe_faced_down = 9574;
	wchar_t pipe_vertical = 9553;
	wchar_t pipe_faced_up = 9577;
	// pipes: ╔, ╗
	wchar_t angle_top_left = 9556;
	wchar_t angle_top_right = 9559;
	// pipes: ╚, ╝
	wchar_t angle_bottom_left = 9562;
	wchar_t angle_bottom_right = 9565;
	// pipe: ╬
	wchar_t cross = 9580;

	Edges horizontal = { 
		pipe_faced_left, pipe_horizontal, pipe_faced_right
	};
	Edges vertical = {
		pipe_faced_down, pipe_vertical, pipe_faced_up
	};
	Angles top = { angle_top_left, angle_top_right };
	Angles bottom = { angle_bottom_left, angle_bottom_right };

	return { horizontal, vertical, top, bottom, cross };
}

static Frame form_edges = InitFormEdges();

#endif
