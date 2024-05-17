#ifndef TASK_STRUCTURE_PROCESS_STRUCTURES_LIST
#define TASK_STRUCTURE_PROCESS_STRUCTURES_LIST

#include <vector>
#include "task/structure/process/structures/container.h"

class List : public Container {
    private:
        std::vector<char> m_real;

    public:
        void Ordered();
        void Insert(char position, char element);
        void InsertTo(char position, char element);
        void Remove(char index);
        void JumpToSearch();
        short Medium();
        char at(char position);
        void Append(char element);
        bool Exists(char position, char element);
        void RemoveAll();
};

#endif
