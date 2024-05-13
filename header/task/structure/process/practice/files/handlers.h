#include <string>
#include <iosfwd>

void Error(std::string operation, const std::ios_base::failure& error);
bool TryCastLong(const std::wstring& s, long* value);
