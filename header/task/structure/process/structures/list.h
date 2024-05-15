#ifndef TASK_STRUCTURE_PROCESS_STRUCTURES_LIST
#define TASK_STRUCTURE_PROCESS_STRUCTURES_LIST

#include <vector>
#include "task/structure/process/structures/container.h"

class List : public Container {
    private:
        std::vector<char> m_real;

    public:
        void Ordered();
        char at(char position);
        bool Exists(char position, char element);
        void Append(char element);
        void Insert(char position, char element);
        void InsertTo(char position, char element);
        void RemoveAll();
        void Remove(char index);
        short Medium();
};

#endif
