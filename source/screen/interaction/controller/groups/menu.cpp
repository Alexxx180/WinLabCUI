#include "screen/interaction/controller/groups/menu.h"
#include "screen/interaction/controller/keyboard.h"

std::vector<char> MenuControls() {
    return { ESC, ENTER, HOME, END, KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT };
}

std::map<byte, std::wstring> MenuInfo() {
    return {
        { HOME, L"[Home] \u0432 \u043d\u0430\u0447\u0430\u043b\u043e" },
        { END, L"[End] \u0432 \u043a\u043e\u043d\u0435\u0446" },
        { ESC, L"[Esc] \u0412\u044b\u0445\u043e\u0434" },
        { ENTER, L"[Enter] \u0432\u044b\u0431\u043e\u0440" },
        { KEY_DOWN, L"[←↕→] \u043d\u0430\u0432\u0438\u0433\u0430\u0446\u0438\u044f" }
    };
}

ControllerGroup menu_input(MenuControls(), MenuInfo());
