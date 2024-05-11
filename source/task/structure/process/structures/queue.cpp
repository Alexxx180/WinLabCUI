#include "task/structure/process/structures/queue.h"
#include "common/codes.h"
#include "input/"

char m_helper[10];
std::queue<char> m_real;

bool Queue :: Exists(char position, char element) {
    return m_helper[position] == element;
}

void Queue :: Append(char element) {
    m_helper[m_size] = element;
    m_real.push(element)   
}

void Queue :: RemoveAll() {
    std::queue<char>().swap(m_real);
}

void Queue :: Remove() {
    Peek();
    Show();
}

char at(char position) {
    return m_helper[position];
}

char Queue :: Peek() {
    char element = m_real.pop();
    ToLast();
    return element;
}
