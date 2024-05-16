#ifndef TASK_STRUCTURE_PROCESS_STRUCTURES_QUEUE
#define TASK_STRUCTURE_PROCESS_STRUCTURES_QUEUE

#include <queue>
#include "task/structure/process/structures/container.h"

class Queue : public Container {
    private:
        char m_helper[10];
        std::queue<char> m_real;

    public:
        bool IsEmpty();
        void Generate();
        void Reset();
        void Search();
        void Show();
        void ShowFirst();
        void ShowLast();
        void Peek();
        void RemoveAll();
};

#endif
