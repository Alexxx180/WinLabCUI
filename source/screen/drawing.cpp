#ifndef SCREEN_ART_DRAWING
#define SCREEN_ART_DRAWING

#include "screen/art/drawing.h"

#include <stdio.h>
#include <conio.h>

#include <string>

// Windows system dependency

#include <windows.h>
#include <iostream>

HANDLE output;
COORD native_windows_cursor;

void SetOutput() { output = GetStdHandle(STD_OUTPUT_HANDLE); }

void MoveCursor(Point* cursor) {
    native_windows_cursor.X = cursor->X;
    native_windows_cursor.Y = cursor->Y;
    SetConsoleCursorPosition(output, native_windows_cursor);
}

void SetCursorShape(CursorShape shape) {
	unsigned char cursor = static_cast<unsigned char>(shape);

	DWORD dwMode;
	GetConsoleMode(output, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(output, dwMode);
	std::wcout << L"\x1b[" << cursor << "\x20q";
}

// Common abstraction code

void HLine(Point* cursor, unsigned char next) { cursor->X = next; }
void VLine(Point* cursor, unsigned char next) { cursor->Y = next; }

void Draw(wchar_t character) {
    _putwch(character);
}

void Clean(short precision) {
    while (--precision > 0) _putwch(L' ');
}

void Write(std::wstring* message) {
    _putws(message->c_str());
}

#endif
