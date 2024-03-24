#ifndef INPUT_LIMITING_BUFFER
#define INPUT_LIMITING_BUFFER

#include "common/types.h"
#include "input/limiting/boundary.h"

#define MAX_BUFFER 5
static const byte ACTUAL_MAX = MAX_BUFFER + 2;

static Boundary<int> result_limits(0, 536870911);

#endif
