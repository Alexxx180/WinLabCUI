#ifndef SCREEN_ART_CONTROLS_MENU_OPTION
#define SCREEN_ART_CONTROLS_MENU_OPTION

#include <string>
#include <vector>

#include "screen/art/controls/menu/menuitem.h"
#include "screen/art/controls/menu/navigation.h"

class Option : public Navigation {
    private:
		//MenuItem* m_menu = NULL;
        std::string* m_caption;
        std::vector<std::string> m_values;
        Boundary<short> edges;
        short m_selection;

        void Iterate(short axis) {
            short next = m_selection + axis;
            if (!edges.Verify(next)) {
                Current(next);
                *m_caption = m_values[m_selection];
				Pen::ink().screen->Clear();
				Pen::ink().Quote(*m_caption);
            }
        }

    protected:
        void Previous() { Iterate(-1); }
        void Next() { Iterate(1); }
        char Action() { Next(); return ENTER; }

    public:
        short SelectedIndex() { return m_selection; }

        Option* Current(short next) {
            m_selection = next;
            return this;
        }

        Option* Values(std::vector<std::string> values) {
            m_values = values;
            edges.Set(0, m_values.size() - 1);
            return this;
        }

		//void BindMenuItem(MenuItem* item) { m_menu = item; }

        void BindCaption(std::string* caption) {
            m_caption = caption;
            *m_caption = m_values[m_selection];
        }
};

#endif
