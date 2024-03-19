#include "screen/drawing/drawing.h"

#include <stdio.h>
#include <conio.h>
#include <string>

// Common abstraction code
void Draw(wchar_t character) {
    _putwch(character);
}

void Clean(short precision) {
    while (--precision > 0) _putwch(L' ');
}

void Write(std::wstring* message) {
    _putws(message->c_str());
}

byte HPoint(Point* cursor) {
    return cursor->X;
}
byte VPoint(Point* cursor) {
    return cursor->Y;
}
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
