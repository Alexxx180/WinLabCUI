#include "screen/matrix/tools/layer/layer.h"

void Layer :: Add(Screen* screen) {
    back.Add(screen->back);
    out.Add(screen->out);
}

void Layer :: Target(byte current) {
    back.Target(current);
    out.Target(current);
    status.Target(current);
}

void Layer :: Redraw() {
    char size = back.size();
    while (--size >= 0)
        back.at(size).Show();
}
