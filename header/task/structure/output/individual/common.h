#ifndef NAMEOF
#define NAMEOF(variable) ((decltype(&variable))nullptr, #variable)

void ArrayOutput(char size, char* array);
void ArraysOutput(char count, char size, char** arrays);

#endif
