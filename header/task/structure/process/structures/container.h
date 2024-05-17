#ifndef TASK_STRUCTURE_PROCESS_PRACTICE_STRUCTURES_CONTAINER
#define TASK_STRUCTURE_PROCESS_PRACTICE_STRUCTURES_CONTAINER

#include "common/types.h"

class Container {
    protected:
        char m_size = 0;
        const byte m_max = 10;

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
        virtual char at(char position) = 0;
        virtual void Append(char element) = 0;
        virtual bool Exists(char position, char element) = 0;
        virtual void RemoveAll() = 0;
};

#endif
