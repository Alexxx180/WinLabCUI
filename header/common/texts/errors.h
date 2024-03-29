#ifndef COMMON_TEXTS_ERRORS
#define COMMON_TEXTS_ERRORS

#include <map>
#include <string>

static std::map<std::string, std::wstring> errors = {
    { "overflow", L"\u041e\u0448\u0438\u0431\u043a\u0430\u003a\u0020\u043d\u0435\u0020\u0432\u0432\u043e\u0434\u0438\u0442\u0435\u0020\u0431\u043e\u043b\u044c\u0448\u0435\u0020\u0441\u0438\u043c\u0432\u043e\u043b\u043e\u0432\u0020\u0447\u0435\u043c %i.\n" },
    { "empty_string", L"\u041e\u0448\u0438\u0431\u043a\u0430\u003a\u0020\u0432\u0432\u0435\u0434\u0435\u043d\u0430\u0020\u043f\u0443\u0441\u0442\u0430\u044f\u0020\u0441\u0442\u0440\u043e\u043a\u0430.\n" },
    { "invalid_character", L"\u041e\u0448\u0438\u0431\u043a\u0430\u003a\u0020\u043d\u0435\u043a\u043e\u0440\u0440\u0435\u043a\u0442\u043d\u044b\u0439\u0020\u0441\u0438\u043c\u0432\u043e\u043b.\n" }
};

#endif
