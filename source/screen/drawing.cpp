#ifndef SCREEN_ART_DRAWING
#define SCREEN_ART_DRAWING

#include "screen/art/drawing.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include <string>

COORD native_windows_cursor;

void HLine(Point* cursor, short next) { cursor->X = next; }
void VLine(Point* cursor, short next) { cursor->Y = next; }

void MoveCursor(Point* cursor) {
    native_windows_cursor.X = cursor->X;
    native_windows_cursor.Y = cursor->Y;

    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, *native_windows_cursor);
}

void Draw(Point* cursor, wchar_t character) {
    MoveCursor(cursor);
    _putwch(character);
}

void Clean(Point* cursor, short precision) {
    MoveCursor(cursor);
    while (--precision > 0) _putwch(L' ');
}

void Write(Point* cursor, std::wstring* message) {
    MoveCursor(cursor);
    _putws(message->c_str());
}

void Field(COORD* space, const short size) {
    Clean(space, size);

    COORD field = *space;
    field.X--;
    Draw(&field, L'|');
    field.Y++;

    short i = size;
    while (--i > 0) {
        field.X++;
        Draw(&field, L'‾'); 
    }

    MoveCursor(space);
}

#endif
