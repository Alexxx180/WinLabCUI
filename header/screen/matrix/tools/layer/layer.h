#include "screen/matrix/fragment.h"

struct Layer {
    Fragment<Grid> back;
    Fragment<Stencil> out;
    Fragment<Bar> status;

    void Add(Screen* screen) {
        back.Add(&screen->back);
        out.Add(&screen->out);
    }

    void Target(byte current) {
        back.Target(current);
        out.Target(current);
        status.Target(current);
    }

    void Redraw() {
        std::vector<Grid>::iterator panel;
        for (panel = back.begin(); panel != back.end(); panel++)
            panel->Show();
    }
};
