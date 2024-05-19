#ifndef TASK_STRUCTURE_PROCESS_STRUCTURES_STACK
#define TASK_STRUCTURE_PROCESS_STRUCTURES_STACK

#include <stack>
#include "task/structure/process/structures/container.h"

class Stack : public Container {
    private:
        char m_helper[10];
        std::stack<char> m_real;

    public:
        char Minimal();
        void JumpToSearch();
        char at(char position);
        void Append(char element);
        bool Exists(char position, char element);
        void RemoveAll();
        void Remove();
};

#endif
