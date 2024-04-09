#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_ITERATOR
#define TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_ITERATOR

#include <vector>

#include "task/structure/process/sort/hoar/types/stack.h"

class HoarIterator {
    private:
        HoarStack m_left, m_right;
        long m_position;

        long GetMiddle();
        bool IsSmallerOneLeft();
        bool HasQueries();
        void Update();

        void Shift(HoarStack& bigger, HoarStack& lesser,
            const int& current, const int& reserve);
        void Arrange(const int& middle,
            const int& left, const int& right);
        void Iteration(std::vector<short>& memory,
            const int& middle, int& left, int& right);
        void Pivots(std::vector<short>& memory);

    public:

        HoarIterator(long size);
        void Sort(std::vector<short>& memory);
};

#endif
