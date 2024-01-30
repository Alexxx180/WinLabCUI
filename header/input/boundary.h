#include <iostream>

#ifndef FORMS_INPUT_BOUNDARY
#define FORMS_INPUT_BOUNDARY

template<typename TYPE>
struct Boundary {
    TYPE start;
    TYPE end;

    Boundary() { }
    Boundary(TYPE p1, TYPE p2) {
        start = p1;
        end = p2;
    }

    bool Verify(TYPE target) {
        return target < start || target > end;
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
