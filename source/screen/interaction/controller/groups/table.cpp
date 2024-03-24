#include "screen/interaction/controller/groups/table.h"
#include "screen/interaction/controller/keyboard.h"

std::vector<char> TableControls() {
    return { ESC, HOME, END, PAGE_UP, PAGE_DOWN };
}

std::map<byte, std::wstring> TableInfo() {
    return {
        { HOME, L"[Home] \u0432 \u043d\u0430\u0447\u0430\u043b\u043e" },
        { END, L"[End] \u0432 \u043a\u043e\u043d\u0435\u0446" },
        { PAGE_UP, L"[Page Up] \u0432\u0432\u0435\u0440\u0445" },
        { PAGE_DOWN, L"[Page Down] \u0432\u043d\u0438\u0437" },
        { ESC, L"[Esc] \u0412\u044b\u0445\u043e\u0434" }
    };
}

ControllerGroup table_input(TableControls(), TableInfo());
