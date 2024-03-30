#ifndef INPUT_LIMITING_BOUNDARY
#define INPUT_LIMITING_BOUNDARY

template<typename TYPE>
struct Boundary {
    TYPE start, end;

    Boundary() {}
    Boundary(TYPE p1, TYPE p2) {
        Set(p1, p2);
    }

    bool Deny(TYPE target) {
        return target < start || target > end;
    }

    void Set(TYPE p1, TYPE p2) {
        start = p1;
        end = p2;
    }
};

#endif
