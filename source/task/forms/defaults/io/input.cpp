#include "task/forms/defaults/io/input.h"

Boundary<char> limits(-99, 99);
Verifier<char>* numeric = new Verifier<char>(limits);
StringInput* prompts = new StringInput();
Randomizer<char> gen_int8(limits);
