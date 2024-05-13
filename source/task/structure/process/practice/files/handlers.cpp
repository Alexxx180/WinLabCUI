#include "task/structure/process/practice/files/handlers.h"

void Error(std::string operation, const std::ios_base::failure& error) {
    out->Target(FOOT)->Jump()->Move()->Clip(operation)->Line()->Move();
    std::cerr << error.what();
    out->Target(MENU)->Move();
}

inline bool TryCastLong(const std::wstring& s, long* value)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char* p;
    *value = wcstol(s.c_str(), &p, 10);

    return (*p == 0);
}
