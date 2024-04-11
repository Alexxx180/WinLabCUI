#include "screen/matrix/types/change/invokations.h"

byte HPoint(Point* cursor) { return cursor->X; }

byte VPoint(Point* cursor) { return cursor->Y; }

void HLine(Point* cursor, byte next) {
    cursor->X = next;
}

void VLine(Point* cursor, byte next) {
    cursor->Y = next;
}

void HRatio(Point* cursor, float relation) {
    cursor->X *= relation;
}

void VRatio(Point* cursor, float relation) {
    cursor->Y *= relation;
}
