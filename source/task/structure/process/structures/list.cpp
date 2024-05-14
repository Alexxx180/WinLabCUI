#include "task/structure/process/structures/queue.h"
#include "screen/interaction/interaction.h"

void List :: Description() {
    // Queue full info
}

void List :: Ordered() {
    Reset();
    char min = 0, value;
    while (m_size < m_max) {
        value = Random();
        if (value < at(min)) {
            min = m_size;
            InsertTo(min, value)
        } else {
            Append(value);
        }
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
    Insert(m_real.begin() + position, element);
}

void List :: RemoveAll() {
    m_real.clear();
}

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
