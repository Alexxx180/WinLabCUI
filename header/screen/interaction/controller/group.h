#ifndef SCREEN_INTERACTION_CONTROLLER_GROUP
#define SCREEN_INTERACTION_CONTROLLER_GROUP

#include <vector>
#include <string>
#include <map>

#include "common/types.h"

class ControllerGroup {
    private:
        std::map<byte, std::wstring> m_info;

    public:
        std::vector<char> controls;

        ControllerGroup(std::vector<char> keys, std::map<byte, std::wstring> info);
        void Print(byte form);
};

#endif
