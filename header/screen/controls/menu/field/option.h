#ifndef SCREEN_CONTROLS_MENU_FIELD_OPTION
#define SCREEN_CONTROLS_MENU_FIELD_OPTION

#include <string>
#include <vector>

#include "input/limiting/boundary.h"
#include "screen/interaction/navigation.h"

class Option : public Navigation {
    private:
        std::vector<std::string> m_values;
        Boundary<short> m_edges;
        short m_selection = 0;

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
        Option();
        Option(std::vector<std::string> parameters);
        void Draw();
        short Choice();
        char Query();
        Option* Current(short next);
        Option* Values(std::vector<std::string> values);
};

#endif
