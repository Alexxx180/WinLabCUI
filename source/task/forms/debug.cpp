#include "task/forms/debug.h"

#include <stdlib.h>
#include <string.h>

#include "common/types.h"
#include "input/feedback/verifier.h"

unsigned short i;

void initDbgVars(int argc, char **argv)
{
    for (i = 1; i < argc; i++) setDbgVar(argv);
}

void setDbgVar(char **argv) {
    if (strcmp(argv[i], "-c") == 0) {
        page_character_results = true;
        return;
    }
    if (strcmp(argv[i++], "-l") == 0)
        page_listing = atoi(argv[i]);
}

// Debug Variables
bool page_character_results = false;
int page_listing = 1;

Verifier<char>* numeric = new Verifier<char>();
