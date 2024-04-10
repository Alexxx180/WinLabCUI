#ifndef MAX_BUFFER
#define MAX_BUFFER 5

#include "input/feedback/limiting/stringify.h"

static constexpr byte ACTUAL_MAX = MAX_BUFFER + 2;
static std::wstring SMAX_BUFFER = Stringify(MAX_BUFFER);

#endif
