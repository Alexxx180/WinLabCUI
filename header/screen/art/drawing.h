#ifndef SCREEN_DRAWING
#define SCREEN_DRAWING

#include <string>

#include "screen/art/types/frame.h"
#include "screen/matrix/types/point.h"

enum CursorShape { BLOCK = 1, UNDERSCORE = 3, BAR = 5 };

static Frame form_edges = InitFormEdges();

void SetOutput();
void MoveCursor(Point* cursor);
void SetCursorShape(CursorShape size);
void Draw(wchar_t character);
void Clean(short precision);
void Write(std::wstring* message);
void HLine(Point* cursor, unsigned char next);
void VLine(Point* cursor, unsigned char next);
void Field(Point* space, short size);

#endif
