#ifndef SCREEN_DRAWING
#define SCREEN_DRAWING

#include <string>

#include "common/types.h"
#include "screen/art/types/frame.h"
#include "screen/matrix/types/point.h"

enum CursorShape { BLOCK = 1, UNDERSCORE = 3, BAR = 5 };
static Frame form_edges = InitFormEdges();
static const byte X = 0, Y = 1;

void SetOutput();
void MoveCursor(Point* cursor);
void SetCursorShape(CursorShape size);
void Draw(wchar_t character);
void Clean(short precision);
void Write(std::wstring* message);
byte HPoint(Point* cursor);
byte VPoint(Point* cursor);
void HLine(Point* cursor, byte next);
void VLine(Point* cursor, byte next);
void HRatio(Point* cursor, float relation);
void VRatio(Point* cursor, float relation);
void Field(Point* space, short size);

#endif
