#include "task/structure/process/practice/files/text/squares.h"
#include "task/structure/process/practice/files/handlers.h"
#include "common/codes.h"
#include <fstream>
#include <string>
#include <iostream>

void TextSearch() {
    unsigned long i = 0;
    std::wifstream file;
    try {
        std::wstring line;
        file.open("demo/input/numbers.txt");
        while (std::getline(file, line))
            if (line.find(L"{keyword}") < line.size())
                std::wcout << ++i << L". " << line;
        file.close();
    }
    catch (const std::ios_base::failure& error) {
        Error("read_failure", error);
        file.close();
    }
}
