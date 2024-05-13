#include "task/structure/process/structures/queue.h"
#include "screen/interaction/interaction.h"

void List :: Description() {
    // Queue full info
}

char List :: at(char position) {
    return m_real.at(position);
}

bool List :: Exists(char position, char element) {
    return at(position) == element;
}

void List :: Append(char element) {
    m_real[m_size++] = element;
}

void List :: Insert(std::vector<char>::iterator pos, char element) {
    m_real.insert(pos, element);
    m_size++;
}

void List :: InsertFirst(char element) {
    m_real.insert(m_real.begin(), element);
}

void List :: InsertLast(char element) {
    m_real.push_back(element);
    m_size++;
}

void List :: InsertTo(char element) {
    // INPUT
    char position = 0;
    Insert(m_real.begin() + position, element);
}

void List :: RemoveAll() {
    m_real.clear();
}

void List :: Remove() {
    m_real.erase(m_real.end() - 1);
    m_size--;
    ToLast();
    Next();
    Show();
}

short List :: Medium() {
    short result = 
    for (char i = 0; i < m_size; i++ 

}
