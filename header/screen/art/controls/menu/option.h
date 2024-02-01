#ifndef SCREEN_ART_CONTROLS_MENU_OPTION
#define SCREEN_ART_CONTROLS_MENU_OPTION

class Option {
    private:
        short m_selection;

        void Iterate(short axis) {
            short next = m_selection + axis;

            if (edges.Verify(next))
                m_selection = next;
        }

    public:
        Boundary<short> edges;

        short SelectedIndex() { return m_selection; }

        void Prev() { Iterate(-1); }
        void Next() { Iterate(1); }
}

#endif

