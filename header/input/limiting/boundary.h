#ifndef INPUT_LIMITING_BOUNDARY
#define INPUT_LIMITING_BOUNDARY

template<typename TYPE>
struct Boundary {
    TYPE start, end;

    Boundary();
    Boundary(TYPE p1, TYPE p2);
    bool Verify(TYPE target);
    void Set(TYPE p1, TYPE p2);
};

#endif
