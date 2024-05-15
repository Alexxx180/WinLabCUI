#ifndef TASK_STRUCTURE_PROCESS_STRUCTURES_STACK
#define TASK_STRUCTURE_PROCESS_STRUCTURES_STACK

#include <stack>
#include "task/structure/process/structures/container.h"

class Stack : public Container {
    private:
        char m_helper[10];
        std::stack<char> m_real;

    public:
        char at(char position);
        bool Exists(char position, char element);
        void Append(char element);
        void RemoveAll();
        void RemoveOne();
        char Minimal();
};

#endif
