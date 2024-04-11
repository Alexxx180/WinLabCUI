#ifndef SCREEN_DRAWING_DRAWING
#define SCREEN_DRAWING_DRAWING

#include <string>
#include "common/types.h"

static const byte X = 0, Y = 1;

void Draw(wchar_t character);
void Clean(short precision);
void Write(std::wstring* message);

#endif
