#include "task/structure/process/structures/queue.h"
#include "screen/interaction/interaction.h"

// Reverse order according FIFO
char Queue :: at(char position) {
    return m_helper[m_max - position - 1];
}

bool Queue :: Exists(char position, char element) {
    return m_helper[position] == element;
}

void Queue :: Append(char element) {
    m_helper[m_size++] = element;
    m_real.push(element);
}

void Queue :: RemoveAll() {
    std::queue<char>().swap(m_real);
}

void Queue :: Remove() {
    m_real.pop();
    ToLast();
    m_size--;
    Next();
    Show();
}
