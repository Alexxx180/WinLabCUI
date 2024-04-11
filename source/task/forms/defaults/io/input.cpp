#include "task/forms/defaults/io/input.h"

Boundary<char> limits(-99, 99);
Verifier<char>* numeric = new Verifier<char>(limits);
StringPrompt* prompts = new StringPrompt();
Randomizer<char> gen_int8(limits);
