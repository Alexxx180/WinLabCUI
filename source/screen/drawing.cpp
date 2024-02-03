#ifndef SCREEN_ART_DRAWING
#define SCREEN_ART_DRAWING

#include "screen/art/drawing.h"

#include <stdio.h>
#include <conio.h>

#include <string>

// Windows system dependency

#include <windows.h>

COORD native_windows_cursor;

void MoveCursor(Point* cursor) {
    native_windows_cursor.X = cursor->X;
    native_windows_cursor.Y = cursor->Y;

    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, *native_windows_cursor);
}

// Common abstraction code

void HLine(Point* cursor, short next) { cursor->X = next; }
void VLine(Point* cursor, short next) { cursor->Y = next; }

void Draw(wchar_t character) {
    _putwch(character);
}

void Clean(char precision) {
    while (--precision > 0) _putwch(L' ');
}

void Write(std::wstring* message) {
    _putws(message->c_str());
}

#endif
