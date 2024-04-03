#ifndef INPUT_PROCESSING_CONVERTER
#define INPUT_PROCESSING_CONVERTER

#include "input/limiting/buffer.h"

#include <stdio.h>
#include <conio.h>
#include <string>

#include "common/texts/errors.h"

template<typename TYPE>
class Converter {
    private:
        static const short system = 10;
        wchar_t* m_end = NULL;
        wchar_t* m_buffer;

        void MarkCharacter() {
            fwprintf(stderr, L"\t%*c\n", (int)(m_end - m_buffer) + 1, '^');
        }

        long ToLong() { return wcstol(m_buffer, &m_end, system); }
        float ToFloat() { return wcstof(m_buffer, &m_end); }
        double ToDouble() { return wcstod(m_buffer, &m_end); }

    public:
        bool HasInvalidData() {
            bool isInvalid = errno != 0 || *m_end != '\0';

            if (isInvalid)
            {
                std::wstring error = errors.at("invalid_character");
                fwprintf(stderr, L"%s\n", error.c_str());
                fwprintf(stderr, L"\t%s\n", m_buffer);
                MarkCharacter();
            }

            return isInvalid;
        }

        void SetBuffer(wchar_t buffer[ACTUAL_MAX]) {
            m_buffer = buffer;
        }

        template <typename TYPE>
        void Convert(TYPE* value) {}

        template <>
        void Convert(char* value) { *value = static_cast<char>(ToLong()); }
        template <>
        void Convert(short* value) { *value = static_cast<short>(ToLong()); }
        template <>
        void Convert(long* value) { *value = ToLong(); }
        template <>
        void Convert(float* value) { *value = ToFloat(); }
        template <>
        void Convert(double* value) { *value = ToDouble(); }
};

#endif
