#ifndef SCREEN_CONTROLS_MENU_FIELD_LABEL
#define SCREEN_CONTROLS_MENU_FIELD_LABEL

#include <string>
#include "screen/interaction/navigation.h"

class Label : public Navigation {
    private:
        std::string m_caption;

    protected:
        char Action();
        char Input();

        void Climb();
        void Slide();
        void First();
        void Last();
        void Next();
        void Previous();

    public:
        Label(std::string caption);
        void Draw();
        short Choice();
};

#endif
