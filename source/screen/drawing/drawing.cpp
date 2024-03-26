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
