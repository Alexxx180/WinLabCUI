#ifndef SCREEN_DRAWING
#define SCREEN_DRAWING

#include <windows.h>

#include <string>

#include "common/types.h"
;
static Frame form_edges = {
    { 9568, 9552, 9571 },
    { 9574, 9553, 9577 },
    { 9556, 9559 },
    { 9562, 9565 },
    9580
};

void MoveCursor(COORD* cursor);
void Draw(COORD* cursor, wchar_t character);
void Clean(COORD* cursor, short precision);
void Write(COORD* text, std::wstring* message);
void HLine(COORD* cursor, short next);
void VLine(COORD* cursor, short next);
void Field(COORD* space, short size);

#endif
