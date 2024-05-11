#ifndef TASK_STRUCTURE_PROCESS_STRUCTURES_QUEUE
#define TASK_STRUCTURE_PROCESS_STRUCTURES_QUEUE

#include <queue>

class Queue {
    private:
        const char m_max_size = 10;
        char m_size = 10;
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
};

#endif
