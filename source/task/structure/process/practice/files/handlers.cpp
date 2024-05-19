#include "task/structure/process/practice/files/handlers.h"

#include "screen/matrix/tools.h"
#include "common/texts/errors.h"

void Error(std::string operation, const std::ios_base::failure& error) {
    std::wstring text = errors.at(operation);
    out->Target(FOOT)->Jump()->Move();
    out->Text(text)->Line()->Move();
    std::cerr << error.what();
    out->Target(MENU)->Move();
}

bool TryCastLong(const std::wstring& s, long* value)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    wchar_t* p;
    *value = wcstol(s.c_str(), &p, 10);

    return (*p == 0);
}
