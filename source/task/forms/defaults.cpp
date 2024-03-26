#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

#include <iostream>
#include <locale>

#include "screen/interaction/controller/keyboard.h"
#include "screen/drawing/platform.h"
#include "task/forms/debug.h"
#include "task/forms/menu/init.h"
#include "task/forms/screen/markdown.h"
#include "task/forms/screen/layers.h"
#include "screen/matrix/tools.h"

void StdLocaleSwitch() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
}

void SetInputOutput() {
    numeric->status.Defaults();
    StdLocaleSwitch();
    SetPlatformOutput();
    SetPlatformShape(BLOCK);
}

void CharacterUserInterface() {
    ScreenMarkdown();
    MenuInit();
    InitLayers();
    SetPenInstance();
}

void SetDefaults(int argc, char** argv) {
    initDbgVars(argc, argv);
    SetInputOutput();
    CharacterUserInterface();
}
