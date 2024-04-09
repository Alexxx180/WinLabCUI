#include "task/structure/shared/painter.h"
#include "task/structure/input/array/choice/input.h"
#include "task/structure/input/array/choice/sort.h"

template<typename TYPE>
void ArrayDefine(SharedArray<TYPE> array) {
    InputDimension(array.original);
    InputChoice(array.original);
    SortChoice(array.sorted);
    
    painter = &array;
}
