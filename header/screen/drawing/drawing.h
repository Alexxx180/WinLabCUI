#include <string>

#include "common/types.h"
#include "screen/matrix/types/point.h"

// Platform system dependencies
#include "screen/drawing/platform.h"

void Draw(wchar_t character);
void Clean(short precision);
void Write(std::wstring* message);

byte HPoint(Point* cursor);
byte VPoint(Point* cursor);
void HLine(Point* cursor, byte next);
void VLine(Point* cursor, byte next);
void HRatio(Point* cursor, float relation);
void VRatio(Point* cursor, float relation);
