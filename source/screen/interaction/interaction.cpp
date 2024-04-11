#include "screen/interaction/interaction.h"

#include <conio.h>
#include <vector>

#include "screen/interaction/lifetime/external.h"
#include "common/codes.h"

std::vector<char> okcancel(2);

bool CodesCheck(char code, std::vector<char> codes) {
    short i = 0, size = codes.size();
    bool exit = code == codes[i];

    while (!exit && ++i < size) exit = code == codes[i];

    return exit;
}

char Next() {
    return _getch();
}

char Next(char target) {
    return Await(Next, target);
}

char Select(std::vector<char> codes) {
    char code;
    bool exit;

    do {
        code = Next();
        exit = CodesCheck(code, codes);
    }
    while (!exit);

    return code;
}

char Select(char cancel, char ok) {
    okcancel[OK] = ok;
    okcancel[FAIL] = cancel;
    return Select(okcancel);
}
