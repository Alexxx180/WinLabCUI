#ifndef SCREEN_DRAWING_PLATFORM
#define SCREEN_DRAWING_PLATFORM

#include "screen/matrix/types/point.h"

enum CursorShape { BLOCK = 1, UNDERSCORE = 3, BAR = 5 };

void SetPlatformOutput();
void MovePlatformCursor(Point* cursor);
void SetPlatformShape(CursorShape size);

#endif
