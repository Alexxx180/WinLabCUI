#include "task/markdown/debug.h"

#include <stdlib.h>
#include <string.h>

#include "common/types.h"
#include "screen/art/controls/menu/option.h"

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

Vector2s efficiency;
Verifier<short>* numeric = new Verifier<short>();

Option array_options[3];
array_options[0].edges.SetBounds(0, 3);
array_options[1].edges.SetBounds(0, 1);
array_options[2].edges.SetBounds(0, 1);
