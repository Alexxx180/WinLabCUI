#ifndef SCREEN_MATRIX_TOOLS_LAYER_FRAGMENT
#define SCREEN_MATRIX_TOOLS_LAYER_FRAGMENT

#include <vector>

#include "common/types.h"

template<typename TYPE>
class Fragment {
    private:
        std::vector<TYPE> m_group = {};

    public:
        TYPE* current;

        TYPE& Fragment<TYPE> :: at(byte selection) {
            return m_group.at(selection);
        }

        byte Fragment<TYPE> :: size() {
            return m_group.size();
        }

        void Fragment<TYPE> :: Add(TYPE* element) {
            m_group.push_back(*element);
        }

        void Fragment<TYPE> :: Target(byte selection) {
            if (selection < m_group.size())
                current = &m_group.at(selection);
        }
};

#endif
