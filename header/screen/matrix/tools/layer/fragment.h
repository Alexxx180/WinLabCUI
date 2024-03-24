#include <vector>

template<typename TYPE>
class Fragment {
    private:
        std::vector<TYPE> m_group = {};

    public:
        TYPE* current;

        std::vector<TYPE>::iterator begin() {
            return m_group.begin();
        }

        std::vector<TYPE>::iterator end() {
            return m_group.end();
        }

        void Add(TYPE* element) {
            m_group.push_back(*element);
        }

        void Target(byte selection) {
            if (selection < m_group.size())
                current = &m_group.at(selection);
        }

};
