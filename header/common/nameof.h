#ifndef NAMEOF

#define NAMEOF(variable) ((decltype(&variable))nullptr, #variable)

#endif
