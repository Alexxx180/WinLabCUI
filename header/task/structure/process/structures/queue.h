#ifndef TASK_STRUCTURE_PROCESS_STRUCTURES_QUEUE
#define TASK_STRUCTURE_PROCESS_STRUCTURES_QUEUE

#include <queue>
#include "task/structure/process/structures/container.h"

class Queue : public Container {
    private:
        char m_helper[10];
        std::queue<char> m_real;

    public:
        void Generate();
        void FromTwo();
        void Reset();
        void JumpToSearch();
        void Show();
        void ShowFirst();
        void ShowLast();
        void Peek();
        char at(char position);
        void Append(char element);
        bool Exists(char position, char element);
        void RemoveAll();
        void Remove();
};

#endif
