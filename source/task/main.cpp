#include "task/main.h"

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

#include <iostream>
#include <locale>
#include <vector>

#include "screen/interaction.h"
#include "task/forms/themes.h"
#include "task/forms/debug.h"
#include "task/forms/markdown.h"
#include "task/structure/input/tasks.h"
#include "common/codes.h"

void StdLocaleSwitch() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);   
}

void SetInput() {
    numeric->status.Defaults();
}

int main(int argc, char** argv)
{
    initDbgVars(argc, argv);

    StdLocaleSwitch();
    SetInput();
    Resize();

    char code = Header();
    if (code == ENTER) Input();
    code = Footer();

    return OK;
}
