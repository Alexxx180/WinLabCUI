#include "input/limiting/boundary.h"

template<typename TYPE>
Boundary<TYPE> :: Boundary() {}

template<typename TYPE>
Boundary<TYPE> :: Boundary(TYPE p1, TYPE p2) {
    Set(p1, p2);
}

template<typename TYPE>
bool Boundary<TYPE> :: Verify(TYPE target) {
    return target < start || target > end;
}

template<typename TYPE>
void Boundary<TYPE> :: Set(TYPE p1, TYPE p2) {
    start = p1;
    end = p2;
}
