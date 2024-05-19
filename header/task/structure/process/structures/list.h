#ifndef TASK_STRUCTURE_PROCESS_STRUCTURES_LIST
#define TASK_STRUCTURE_PROCESS_STRUCTURES_LIST

#include <vector>
#include "task/structure/process/structures/container.h"

class List : public Container {
    private:
        std::vector<char> m_real;
        typedef bool (*is)(char left, char right);

        char Change(is dir, char value, char middle, char correction);
        void DirectionalSort(char value);

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
