#include "task/lab3.h"

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <locale>
#include <vector>

#include "screen/interaction.h"
#include "screen/themes.h"
#include "task/structure/input.h"
#include "task/structure/output.h"
#include "task/structure/process/preprocess.h"
#include "task/structure/process.h"
#include "task/markdown/debug.h"
#include "task/markdown.h"
#include "common/codes.h"
#include "common/types.h"

void StdLocaleSwitch() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);   
}

char Program() {
    Loop2 arguments;
    do {
        arguments = Input();
    }
    while (Preprocess(&arguments));
   
    std::vector<Answer> results = Process(&arguments);

    Output(results);

    return Await(OutputControl, ESC);
}

int main(int argc, char **argv)
{
    initDbgVars(argc, argv);

    StdLocaleSwitch();
    Resize();

    char code = Header();
    if (code == ENTER)
        code = Program();
    code = Footer();

    return OK;
}
