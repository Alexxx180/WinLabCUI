#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_ITERATOR
#define TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_ITERATOR

#include <vector>

#include "task/structure/process/sort/hoar/types/stack.h"
#include "task/structure/process/sort/utils/swap.h"
#include "task/structure/process/sort/utils/efficiency.h"

class HoarIterator {
    private:
        HoarStack m_left, m_right;
        long m_position;

        long GetMiddle() {
            return (m_left.Index + m_right.Index) >> 1;
        }

        bool IsSmallerOneLeft() {
            return Comparison(m_left.Index < m_right.Index);
        }

        bool HasQueries() {
            return Comparison(m_position != 0);
        }

        void Update() {
            m_left.Update(m_position);
            m_right.Update(m_position);
            m_position--;
        }

        bool IsBigger(const int& left, long& right) {
            return Comparison(left > right);
        }

        bool IsLesser(const int& left, long& right) {
            return Comparison(left < right);
        }

        void Shift(
            bool (HoarIterator::*condition)(const int&, long&),
            HoarStack& left, HoarStack& right,
            const int& current, const int& reserve) {

            if ((this->*(condition))(current, right.Index)) {
                m_position++;
                left.Stack[m_position] = current;
                right.Update(m_position);
            }
            right.Index = reserve;

        }

        void Arrange(const int& middle, const int& left, const int& right) {
            if (left < middle)
                Shift(&HoarIterator::IsLesser, m_left, m_right, left, right);
            else
                Shift(&HoarIterator::IsBigger, m_right, m_left, right, left);
        }

        template<typename TYPE>
        void Iteration(std::vector<TYPE>& memory,
            const int& middle, int& left, int& right) {
            TYPE pivot = memory[middle];
            do {
                while (Comparison(memory[left] < pivot)) left++;
                while (Comparison(memory[right] > pivot)) right--;

                if (Comparison(left <= right)) {
                    SwapMemory(memory, left, right);
                    permutations++; left++; right--;
                }
            } while (Comparison(left <= right));
        }

        template<typename TYPE>
        void Pivots(std::vector<TYPE>& memory) {
            int left, right;
            do {
                const int middle = GetMiddle();
                left = m_left.Index;
                right = m_right.Index;

                Iteration(memory, middle, left, right);
                Arrange(middle, left, right);
            } while (IsSmallerOneLeft());
        }

    public:
        HoarIterator(long size) {
            ResetStats();
            m_position = 1;
            m_left.Stack[m_position] = 0;
            m_right.Stack[m_position] = size - 1;
        }

        template<typename TYPE>
        void Sort(std::vector<TYPE>& memory) {
            do {
                Update();
                Pivots(memory);
            } while (HasQueries());
        }
};

#endif
