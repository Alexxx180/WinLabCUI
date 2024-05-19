#include "task/structure/process/structures/list.h"
#include "screen/interaction/interaction.h"
#include <iostream>

bool IsLeft(char left, char right) { return left >= right; }
bool IsRight(char left, char right) { return left < right; }

char List :: Change(is dir, char value, char middle, char correction) {
    while (dir(value, at(middle))) middle += correction;
    return middle;
}

void List :: DirectionalSort(char value) {
    char middle = m_size / 2;
    if (IsLeft(value, at(middle)))
        middle = Change(IsLeft, value, middle, 1);
    else
        middle = Change(IsRight, value, middle, -1) + 1;
    InsertTo(middle, value);
}

void List :: Ordered() {
    Reset();
    char value = Random();
    Append(value);
    while (m_size < m_max) {
        value = Random();
        if (value >= at(m_size - 1))
            Append(value);
        else if (value <= at(0))
            InsertTo(0, value);
        else
            DirectionalSort(value);
    }
}

char List :: at(char position) {
    return m_real.at(position);
}

bool List :: Exists(char position, char element) {
    return at(position) == element;
}

void List :: Append(char element) {
    m_real.push_back(element);
    m_size++;
}

void List :: Insert(char position, char element) {
    m_real.insert(m_real.begin() + position, element);
    m_size++;
}

void List :: InsertTo(char position, char element) {
    Insert(position, element);
}

void List :: RemoveAll() { m_real.clear(); }

void List :: Remove(char index) {
    m_real.erase(m_real.begin() + index);
    m_size--;
}

short List :: Medium() {
    short result = 0;
    char i = m_size;
    while (--i >= 0) result += at(i);
    return result;
}
