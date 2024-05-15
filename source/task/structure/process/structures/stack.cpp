#include "task/structure/process/structures/stack.h"
#include "screen/interaction/interaction.h"

char Stack :: at(char position) {
    return m_helper[position];
}

bool Stack :: Exists(char position, char element) {
    return m_helper[position] == element;
}

void Stack :: Append(char element) {
    m_helper[m_size++] = element;
    m_real.push(element);
}

void Stack :: RemoveAll() {
    std::stack<char>().swap(m_real);
}

void Stack :: RemoveOne() {
    m_real.pop();
    ToLast();
    m_size--;
    Next();
    Show();
}

char Stack :: Minimal() {
    char i = m_size;
    char min = i - 1;

    while (--i >= 0) if (m_helper[i] < m_helper[min]) min = i;

    return min;
}
