#ifndef COMMON_CALCULUS_POW
#define COMMON_CALCULUS_POW

template<TYPE>
TYPE pow(TYPE base, byte exp) {
    TYPE result = 1;
    while (exp) {
        if (exp % 2) result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

#endif
