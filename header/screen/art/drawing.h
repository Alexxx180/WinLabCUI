#ifndef SCREEN_DRAWING
#define SCREEN_DRAWING

#include <string>

#include "screen/art/types/frame.h"
#include "screen/matrix/types/point.h"

static Frame form_edges = {
    { 9568, 9552, 9571 },
    { 9574, 9553, 9577 },
    { 9556, 9559 },
    { 9562, 9565 }, 9580
};

void MoveCursor(Point* cursor);
void Draw(wchar_t character);
void Clean(short precision);
void Write(std::wstring* message);
void HLine(Point* cursor, unsigned char next);
void VLine(Point* cursor, unsigned char next);
void Field(Point* space, short size);

#endif
