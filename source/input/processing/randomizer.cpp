#include <cstdlib>

template <typename TYPE>
Randomizer<TYPE> :: Randomizer() {}

template <typename TYPE>
Randomizer<TYPE> :: Randomizer(Boundary<TYPE> interval) {
    Set(interval);
}

template <typename TYPE>
Randomizer<TYPE>* Randomizer<TYPE> :: Set(Boundary<TYPE> interval) {
    limits = interval;
    return this;
}

template <typename TYPE>
long Randomizer<TYPE> :: Size(TYPE start, TYPE end) {
    return static_cast<long>(abs(start) + end + 1);
}

template <typename TYPE>
TYPE Randomizer<TYPE> :: Standard() {
    long size = Size(limits.start, limits.end);
    return rand() % size + limits.start;
}

template <typename TYPE>
TYPE Randomizer<TYPE> :: Random() {
    return Standard();
}
