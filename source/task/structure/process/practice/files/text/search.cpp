#include "task/structure/process/practice/files/text/squares.h"
#include "task/structure/process/practice/files/handlers.h"
#include "common/codes.h"
#include "screen/matrix/tools.h"
#include <fstream>
#include <string>

void TextSearch() {
    unsigned long i;
    std::wifstream file;
    out->Target(MAIN)->Page(0)->Line(0)->Move();
    try {
        std::wstring line;
        file.open("demo/input/search.txt");
        for (i = 1; std::getline(file, line); i++)
            if (line.find(L"{keyword}") < line.size())
                out->Text(+i, L". ", line)->Line()->Move();
        file.close();
    }
    catch (const std::ios_base::failure& error) {
        Error("read_failure", error);
        file.close();
    }
    out->Target(MENU)->Move();
}
