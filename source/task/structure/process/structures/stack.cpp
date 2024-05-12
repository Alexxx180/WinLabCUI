#include "task/structure/process/structures/stack.h"
#include "screen/interaction/interaction.h"

void Stack :: Description() {
    // Queue full info
}

// Order according LIFO
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
