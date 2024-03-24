template<class TYPE>
char Await(TYPE* instance, char (TYPE::*program)(), char target);
template<class TYPE>
char Await(TYPE* instance, char (TYPE::&program)(), char target)
