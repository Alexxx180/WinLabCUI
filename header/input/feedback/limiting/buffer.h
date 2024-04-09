#ifndef INPUT_LIMITING_BUFFER
#define INPUT_LIMITING_BUFFER

#include <string>

#include "common/types.h"
#include "input/feedback/limiting/boundary.h"

#define MAX_BUFFER 5
static constexpr byte ACTUAL_MAX = MAX_BUFFER + 2;

static Boundary<int> result_limits(0, 536870911);

std::wstring MaxBufferNumber() {
    std::string max = std::to_string(MAX_BUFFER);
    std::wstring number(max.begin(), max.end());
    return number;
}

#endif
