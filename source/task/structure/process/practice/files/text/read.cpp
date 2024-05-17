#include "task/structure/process/practice/files/text/read.h"
#include "task/structure/process/practice/files/handlers.h"
#include "common/codes.h"
#include <fstream>
#include <string>
#include <iosfwd>

char Head(std::wstring& line) {
    char code = UNDEFINED;
    std::wifstream file;
    try {
        file.open("demo/input/numbers.txt");
        if (file.good()) std::getline(file, line);
        file.close();
        code = OK;
    }
    catch (const std::ios_base::failure& error) {
        Error("read_failure", error);
        file.close();
    }
    return code;
}
