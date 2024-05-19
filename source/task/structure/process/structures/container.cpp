#include "task/structure/process/structures/container.h"
#include "task/forms/defaults/io/input.h"
#include "screen/matrix/tools.h"
#include "common/codes.h"
#include "screen/interaction/interaction.h"

char Container :: Random() { return gen8.Random(); }

bool Container :: IsEmpty() { return m_size == 0; }
bool Container :: HasSpace() { return m_size < m_max; }

void Container :: Randomized() {
    Reset();
    while (m_size < m_max) Append(Random());
}

char Container :: Search(char element) {
    for (char i = 0; i < m_size; i++) if (Exists(i, element)) return i;
    return UNDEFINED;
}

void Container :: Reset() {
    m_size = 0;
    RemoveAll();
}

char Container :: Input() {
    out->Flip(1)->Move()->Clear()->Move();
    numeric->Input();
    char value = numeric->result;
    out->Flip(-1)->Move();
    return value;
}

void Container :: Show() {
    SelectLayer(FLOATING);
    out->Target(MAIN)->Line(0)->Size(1)->Span(1);

    char i = -1;
    while (++i < m_size) {
        out->Line(i)->Move()->Clear()->Move();
        out->Text(+i, L". ", +at(i));
    }

    while (i < m_max)
        out->Line(i++)->Move()->Clear()->Move();

    SelectLayer(SCREEN);
    out->Target(MENU)->Move();
}

void Container :: ToIndex(char index) {
    if (index != -1) {
        SelectLayer(FLOATING);
        out->Target(MAIN)->Line(index)->Move();
        Next();
        SelectLayer(SCREEN);
        out->Target(MENU)->Move();
    }
}

void Container :: ToFirst() { ToIndex(0); }

void Container :: ToLast() { ToIndex(m_size - 1); }
