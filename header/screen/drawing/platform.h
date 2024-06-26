#ifndef SCREEN_DRAWING_PLATFORM
#define SCREEN_DRAWING_PLATFORM

#include "screen/matrix/types/point.h"

enum CursorShape { BLOCK = 1, PLATE = 3, BAR = 5 };

void SetPlatformOutput();
void MoveCursor(Point* cursor);
void SetPlatformShape(CursorShape size);

#endif
