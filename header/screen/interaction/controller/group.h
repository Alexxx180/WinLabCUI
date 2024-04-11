#ifndef SCREEN_INTERACTION_CONTROLLER_GROUP
#define SCREEN_INTERACTION_CONTROLLER_GROUP

#include <vector>
#include <string>
#include <map>

class ControllerGroup {
    private:
        std::map<char, std::wstring> m_info;

    public:
        std::vector<char> controls;

        ControllerGroup(std::vector<char> keys, std::map<char, std::wstring> info);
        void Print();
        void Clear();
};

#endif
