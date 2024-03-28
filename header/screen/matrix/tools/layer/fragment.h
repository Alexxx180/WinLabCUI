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

        TYPE& at(byte selection);
        byte size();
        void Add(TYPE* element);
        void Target(byte selection);
};

#endif
