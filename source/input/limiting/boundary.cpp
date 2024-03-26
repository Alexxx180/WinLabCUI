template<typename TYPE>
Boundary :: Boundary() {}

template<typename TYPE>
Boundary :: Boundary(TYPE p1, TYPE p2) {
    Set(p1, p2);
}

bool Verify(TYPE target) {
    return target < start || target > end;
}

void Set(TYPE p1, TYPE p2) {
    start = p1;
    end = p2;
}
