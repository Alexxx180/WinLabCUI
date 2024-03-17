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
	// if (cursor->X == 0 && cursor->Y == 1) wprintf(L"BAD");
    native_windows_cursor.X = cursor->X;
    native_windows_cursor.Y = cursor->Y;
	// if (cursor->X == 0 && cursor->Y == 1) wprintf(L"GOOD");
    SetConsoleCursorPosition(output, native_windows_cursor);
}

void SetCursorShape(CursorShape shape) {
	byte cursor = static_cast<byte>(shape);

	DWORD dwMode;
	GetConsoleMode(output, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(output, dwMode);
	std::wcout << L"\x1b[" << cursor << "\x20q";
}

// Common abstraction code
byte HPoint(Point* cursor) { return cursor->X; }
byte VPoint(Point* cursor) { return cursor->Y; }
void HLine(Point* cursor, byte next) { cursor->X = next; }
void VLine(Point* cursor, byte next) { cursor->Y = next; }
void HRatio(Point* cursor, float relation) { cursor->X *= relation; }
void VRatio(Point* cursor, float relation) { cursor->Y *= relation; }

void Draw(wchar_t character) {
    _putwch(character);
}

void Clean(short precision) {
    while (--precision > 0) _putwch(L' ');
}

void Write(std::wstring* message) {
    _putws(message->c_str());
}
