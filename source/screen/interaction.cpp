#include "screen/interaction.h"

#include <conio.h>
#include <vector>

bool CodesCheck(char code, std::vector<char> codes) {
    short i = 0, size = codes.size();
    bool exit = code == codes[i];

    while (!exit && ++i < size)
        exit = code == codes[i];

    return exit;
}

char Select(std::vector<char> codes) {
    char code;
    bool exit;

    do {
        code = _getch();
        exit = CodesCheck(code, codes);
    }
    while (!exit);

    return code;
}

char Select(char cancel, char ok) {
    char code;
    bool exit;

    do {
        code = _getch();
        exit = code == cancel || code == ok;
    }
    while (!exit);

    return code;
}

char Next() { return _getch(); }

char Next(char target) { return Await(Next, target); }

char Await(char (*program)(), char target) {
    char code;
    
    do {
        code = program();
    }
    while (code != target);

    return code;
}

void Await(bool (*program)()) {
    bool exit;
    do { exit = program(); } while (!exit);
}
