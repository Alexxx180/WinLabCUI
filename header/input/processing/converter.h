#ifndef SCREEN_INTERACTION_CONVERTER
#define SCREEN_INTERACTION_CONVERTER

#include <stdio.h>
#include <conio.h>
#include <string>

#include "screen/interaction.h"
#include "common/texts/errors.h"

template<typename TYPE>
class Converter {
private:
    static const short system = 10;
    wchar_t* m_end = NULL;
    wchar_t* m_buffer;

    void MarkCharacter() {
        int position = static_cast<int>(m_end - m_buffer) + 1;
        fwprintf(stderr, L"\t%*c\n", position, '^');
    }

public:
    bool HasInvalidData() {
        bool isInvalid = errno != 0;
        isInvalid |= *m_end != '\0';

        if (isInvalid)
        {
            std::wstring text = errors["invalid_character"];
            fwprintf(stderr, L"%s\n", text.c_str());
            fwprintf(stderr, L"\t%s\n", m_buffer);
            MarkCharacter();
        }

        return isInvalid;
    }

    void SetBuffer(wchar_t buffer[ACTUAL_MAX]) {
        m_buffer = buffer;
    }

    template <typename TYPE>
    void Convert(TYPE* value) { }

    template <>
    void Convert(short* value) {
        *value = wcstol(m_buffer, &m_end, system);
    }

    template <>
    void Convert(float* value) { *value = wcstof(m_buffer, &m_end); }
};

#endif
