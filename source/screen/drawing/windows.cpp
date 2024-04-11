// Preprocessing cross-platform code to be placed here...
#include "screen/drawing/platform.h"

#include <iostream>
#include <windows.h>

HANDLE output;
COORD native_windows_cursor;

void SetPlatformOutput() {
    output = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD dwMode;
    GetConsoleMode(output, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(output, dwMode);
}

void MoveCursor(Point* cursor) {
    native_windows_cursor.X = cursor->X;
    native_windows_cursor.Y = cursor->Y;

    //wprintf(L"Pat 2: %i, %i", cursor->X, cursor->Y);

    SetConsoleCursorPosition(output, native_windows_cursor);
}

void SetPlatformShape(CursorShape shape) {
    byte cursor = static_cast<byte>(shape);
    std::wcout << L"\x1b[" << cursor << "\x20q";
}
