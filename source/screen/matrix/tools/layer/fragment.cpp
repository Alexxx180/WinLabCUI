#include "screen/matrix/tools/layer/fragment.h"

template<typename TYPE>
TYPE& Fragment<TYPE> :: at(byte selection) {
    return m_group.at(selection);
}

template<typename TYPE>
byte Fragment<TYPE> :: size() {
    return m_group.size();
}

template<typename TYPE>
void Fragment<TYPE> :: Add(TYPE* element) {
    m_group.push_back(*element);
}

template<typename TYPE>
void Fragment<TYPE> :: Target(byte selection) {
    if (selection < m_group.size())
        current = &m_group.at(selection);
}
