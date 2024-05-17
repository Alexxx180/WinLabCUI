#include "task/structure/process/practice/files/binary.h"
#include "task/structure/process/practice/files/text/read.h"
#include "task/structure/process/practice/files/handlers.h"
#include "common/codes.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iosfwd>

char BinaryWrite(const std::wstring& line) {
    char code = UNDEFINED;
    std::ofstream file;
    try {
        long number;
        size_t bytes = sizeof(long);

        std::vector<long> negative;
        std::wstring word;
        std::wstringstream words(line);

        file.open("demo/output/binary.bin", std::ios::binary);
        while (words >> word && TryCastLong(word, &number))
            if (number > 0)
                file.write((char*) &number, bytes);
            else
                negative.push_back(number);

        long i = negative.size();
        while (--i >= 0) file.write((char*) &negative[i], bytes);

        file.close();
        code = OK;
    }
    catch (const std::ios_base::failure& error) {
        Error("write_failure", error);
        file.close();
    }
    return code;
}

void Binary() {
    std::wstring numbers;
    if (Head(numbers) != UNDEFINED) BinaryWrite(numbers);
}
