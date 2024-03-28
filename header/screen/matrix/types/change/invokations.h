#ifndef SCREEN_MATRIX_TYPES_CHANGE_INVOKATION
#define SCREEN_MATRIX_TYPES_CHANGE_INVOKATION

#include "common/types.h"
#include "screen/matrix/types/point.h"

typedef byte (*point_extract)(Point*);
typedef void (*axis_shift)(Point*, byte);
typedef void (*axis_extend)(Point*, float);

byte HPoint(Point* cursor);
byte VPoint(Point* cursor);
void HLine(Point* cursor, byte next);
void VLine(Point* cursor, byte next);
void HRatio(Point* cursor, float relation);
void VRatio(Point* cursor, float relation);

#endif
