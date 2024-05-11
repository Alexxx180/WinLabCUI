#include "task/structure/process/structures/queue.h"
#include "task/forms/defaults/io/input.h"
#include "screen/matrix/tools.h"
#include "common/codes.h"

bool Container :: IsEmpty() {
    return m_size == 0;
}

void Container :: Randomized() {
    for (m_size = 0; m_size < m_max; m_size++)
        Append(gen_int8.Random());
}

char Container :: Search(char element) {
    for (char i = 0; i < m_size; i++) 
        if (Exists(i, element)) return i;
    return UNDEFINED;
}

void Container :: Reset() {
    m_size = 0;
    RemoveAll();
}

void Queue :: Show() {
    SelectLayer(FLOATING);
    out->Target(MAIN)->Line(0);

    char i = 0;
    while (i < m_size)
        out->Line(i)->Move()->FText(L"%i. ", i)->FText(L"%i", at(i++));

    while (i < m_max)
        out->Line(i++)->Move()->Clear()-Move();
}

void Queue :: ToFirst() {
    out->Target(MAIN)->Line(0)->Move();
}

void Queue :: ToLast() {
    out->Target(MAIN)->Line(m_size - 1)->Move();
}
