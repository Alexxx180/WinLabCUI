#ifndef SCREEN_ART_CONTROLS_MENU_CONTENT_OPTION
#define SCREEN_ART_CONTROLS_MENU_CONTENT_OPTION

#include <string>
#include <vector>

#include "input/boundary.h"
#include "screen/art/controls/menu/navigation.h"

class Option : public Navigation {
    private:
        std::vector<std::string> m_values;
        Boundary<short> m_edges;
        short m_selection = 0;

    protected:
        void Previous();
        void Next();
        char Action();

    public:
        void Draw();
        short Choice();
        char Query();
        Option* Current(short next);
        Option* Values(std::vector<std::string> values);
};

#endif
