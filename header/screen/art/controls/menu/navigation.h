#ifndef SCREEN_ART_CONTROLS_MENU_NAVIGATION
#define SCREEN_ART_CONTROLS_MENU_NAVIGATION

#include <vector>
#include "screen/interaction.h"

static std::vector<char> menu_input_keys = {
    ESC, ENTER, KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT
};

class Navigation {
    protected:
        char Action();
        void Previous();
        void Next();

    public:
        virtual void Draw() = 0;
        short Choice();
        char Query();
};

#endif
