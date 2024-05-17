#include "task/structure/process/structures/queue.h"
#include "screen/interaction/interaction.h"
#include <set>

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
}

void Queue :: FromTwo() {
    Reset();

    const char size = 2;
    std::queue<char> initial[2];
    for (char j = size, i = 0; i < 5; i++, j = size)
        while (j-- > 0) initial[j].push(Random());

    std::set<char> unique;
    for (char j = size, i = 0; i < 5; i++, j = size)
        while (j-- > 0) {
            char element = initial[j].front();
            initial[j].pop();
            if (unique.find(element) != unique.end())
                unique.insert(element);
        }
    
    std::set<char>::iterator element = unique.begin();
    while (element != unique.end()) {
        m_real.push(*element);
        element++;
    }
}
