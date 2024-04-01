#ifndef NAMEOF

#include <string>

#define NAMEOF(variable) ((void)variable, #variable)

#endif
