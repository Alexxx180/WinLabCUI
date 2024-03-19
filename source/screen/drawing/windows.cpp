// Preprocessing cross-platform code to be placed here...
#include "screen/drawing/platform.h"

#include <iostream>
#include <windows.h>

HANDLE output;
COORD native_windows_cursor;

void SwitchMode(DWORD next) {
    DWORD dwMode;
    GetConsoleMode(output, &dwMode);
    SetConsoleMode(output, dwMode | next);
}


void SetOutput() {
    output = GetStdHandle(STD_OUTPUT_HANDLE);
    SwitchMode(ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void MoveCursor(Point* cursor) {
    // if (cursor->X == 0 && cursor->Y == 1) wprintf(L"BAD");
    native_windows_cursor.X = cursor->X;
    native_windows_cursor.Y = cursor->Y;
    // if (cursor->X == 0 && cursor->Y == 1) wprintf(L"GOOD");
    SetConsoleCursorPosition(output, native_windows_cursor);
}

void SetCursorShape(CursorShape shape) {
    byte cursor = static_cast<byte>(shape);
    std::wcout << L"\x1b[" << cursor << "\x20q";
}
