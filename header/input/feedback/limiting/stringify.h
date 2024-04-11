#include <string>
#include "common/types.h"

static std::wstring Stringify(byte number) {
    std::string value = std::to_string(number);
    return std::wstring(value.begin(), value.end());
}
