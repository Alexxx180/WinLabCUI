#include "input/processing/converter.h"

#include <stdio.h>
#include <conio.h>
#include <string>

#include "common/texts/errors.h"

template<typename TYPE>
void Converter<TYPE> :: MarkCharacter() {
    int position = static_cast<int>(m_end - m_buffer) + 1;
    fwprintf(stderr, L"\t%*c\n", position, '^');
}

template<typename TYPE>
bool Converter<TYPE> :: HasInvalidData() {
    bool isInvalid = errno != 0;
    isInvalid |= *m_end != '\0';

    if (isInvalid)
    {
        std::wstring text = errors.at("invalid_character");
        fwprintf(stderr, L"%s\n", text.c_str());
        fwprintf(stderr, L"\t%s\n", m_buffer);
        MarkCharacter();
    }

    return isInvalid;
}

template<typename TYPE>
void Converter<TYPE> :: SetBuffer(wchar_t buffer[ACTUAL_MAX]) {
    m_buffer = buffer;
}
