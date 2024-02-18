#ifndef SCREEN_ART_CONTROLS_MENU_NAVIGATION
#define SCREEN_ART_CONTROLS_MENU_NAVIGATION

#include <string>
#include <vector>

#include "screen/interaction.h"

static std::vector<char> menu_input_keys = {
    ESC, ENTER, KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT
};

class Navigation {
    protected:
        virtual void Action() = 0;
        virtual void Previous() = 0;
        virtual void Next() = 0;

    public:
        char Query() {
            char code = Select(menu_input_keys);

            switch (code) {
                case ENTER:
                    Action();
                    break;
                case KEY_UP:
                case KEY_LEFT:
                    Previous();
                    break;
                case KEY_DOWN:
                case KEY_RIGHT:
                    Next();
                    break;
                default:
                    break;
            }

            return code;
        }
};

#endif
