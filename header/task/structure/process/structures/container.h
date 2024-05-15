#ifndef TASK_STRUCTURE_PROCESS_PRACTICE_STRUCTURES_CONTAINER
#define TASK_STRUCTURE_PROCESS_PRACTICE_STRUCTURES_CONTAINER

#include "common/types.h"

class Container {
    private:
        char m_size = 0;
        const byte m_max = 10;
        const byte bytes = 8;

    public:
        const char& size = m_size;

        bool IsEmpty();
        bool HasSpace();
        void Randomized();
        char Search(char element);
        void Reset();
        char Random();
        char Input();
        void Show();
        void ToIndex(char index);
        void ToFirst();
        void ToLast();
        void RemoveAll() = 0;
};

#endif
