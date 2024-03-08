#ifndef SCREEN_DRAWING
#define SCREEN_DRAWING

#include <string>

#include "screen/art/types/frame.h"
#include "screen/matrix/types/point.h"

static Frame form_edges = InitFormEdges();

void MoveCursor(Point* cursor);
void Draw(wchar_t character);
void Clean(short precision);
void Write(std::wstring* message);
void HLine(Point* cursor, unsigned char next);
void VLine(Point* cursor, unsigned char next);
void Field(Point* space, short size);

#endif
