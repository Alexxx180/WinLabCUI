#include "task/structure/process/practice/files/text/squares.h"
#include "task/structure/process/practice/files/text/read.h"
#include "task/structure/process/practice/files/handlers.h"
#include "common/codes.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iosfwd>

char Write(const std::wstring& line) {
    char code = UNDEFINED;
    try {
        long number;
        std::wstring word;
        std::ofstream file("demo/output/squares.txt");
        std::stringstream words(line);
        while (words >> word && TryCastLong(word, &number))
            file << pow(number, 2) << L' ';
        file.close();
        code = OK;
    }
    catch (const std::ios_base::failure& error) {
        Error("write_failure", error);
        file.close();
    }
    return code;
}

void SquareEnum() {
    std::wstring numbers;
    if (Head(numbers) != UNDEFINED) Write(numbers);
}
