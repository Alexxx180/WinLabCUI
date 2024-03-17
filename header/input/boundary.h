#ifndef INPUT_BOUNDARY
#define INPUT_BOUNDARY

#include <iostream>

template<typename TYPE>
struct Boundary {
    TYPE start;
    TYPE end;

    Boundary() { }
    Boundary(TYPE p1, TYPE p2) {
        Set(p1, p2);
    }

    bool Verify(TYPE target) {
        return target < start || target > end;
    }

    void Set(TYPE p1, TYPE p2) {
        start = p1;
        end = p2;
    }

    void View() {
        std::wcout << L"<";
        std::wcout << start;
        std::wcout << L", ";
        std::wcout << end;
        std::wcout << L">";
    }
};

#endif
