#include "screen/art/drawing.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include <string>

void MoveCursor(COORD* cursor) {
    HANDLE handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handleOutput, *cursor);
}

void Draw(COORD* cursor, wchar_t character) {
    MoveCursor(cursor);
    _putwch(character);
}

void Clean(COORD* cursor, short precision) {
    MoveCursor(cursor);
    while (--precision > 0) _putwch(L' ');
}

void Write(COORD* text, std::wstring* message) {
    MoveCursor(text);
    _putws(message->c_str());
}

void HLine(COORD* cursor, short next) { cursor->X = next; }
void VLine(COORD* cursor, short next) { cursor->Y = next; }

void Field(COORD* space, short size) {
    Clean(space, size);

    COORD field = *space;
    field.X--;
    Draw(&field, L'|');
    field.Y++;

    for (short i = 0; i < size; i++) {
        field.X++;
        Draw(&field, L'‾'); 
    }

    MoveCursor(space);
}
