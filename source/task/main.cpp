﻿#include "task/main.h"
#include "task/forms/defaults.h"
#include "task/structure/program.h"

int main(int argc, char** argv) {
    SetDefaults(argc, argv);
    return Program();
}
