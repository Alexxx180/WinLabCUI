#include "task/structure/process/practice/files/text/squares.h"
#include "task/structure/process/practice/files/handlers.h"
#include "common/codes.h"
#include <fstream>
#include <string>
#include <iosfwd>

void TextSearch() {
    unsigned long i = 0;
    try {
        std::wstring line;
        std::ifstream file("demo/input/numbers.txt");
        while (std::getline(infile, line))
            if (line.find("{keyword}") < line.size())
                std::wcout << ++i << L". " << line;
    }
    catch (const std::ios_base::failure& error) {
        Error("read_failure", error);
        file.close();
    }
}
