#ifndef SCREEN_ART_CONTROLS_MENU_CONTENT_OPTION
#define SCREEN_ART_CONTROLS_MENU_CONTENT_OPTION

#include <string>
#include <vector>

#include "input/boundary.h"
#include "screen/art/controls/menu/content/field.h"

class Option : public Field {
    private:
        std::vector<std::string> m_values;
        Boundary<short> m_edges;
        short m_selection = 0;

    protected:
        void Previous() { Current(m_selection - 1); Draw(); }
        void Next() { Current(m_selection + 1); Draw(); }
        char Action() { Next(); return ENTER; }

    public:
		void Draw() { Pen::ink().Quote(m_values[m_selection]); }

        short SelectedIndex() { return m_selection; }

        Option* Current(short next) {
            if (m_edges.Verify(next))
				return this;

			m_selection = next;
            return this;
        }

        Option* Values(std::vector<std::string> values) {
            m_values = values;
            m_edges.Set(0, m_values.size() - 1);
            return this;
        }
};

#endif
