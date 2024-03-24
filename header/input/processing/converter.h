#ifndef INPUT_PROCESSING_CONVERTER
#define INPUT_PROCESSING_CONVERTER

#include "input/limiting/buffer.h"
#include "common/texts/errors.h"

template<typename TYPE>
class Converter {
    private:
        static const short system = 10;
        wchar_t* m_end = NULL;
        wchar_t* m_buffer;

        void MarkCharacter();

    public:
        bool HasInvalidData();
        void SetBuffer(wchar_t buffer[ACTUAL_MAX]);

        template <typename TYPE>
        void Convert(TYPE* value) {}

        template <>
        void Convert(short* value) {
            *value = wcstol(m_buffer, &m_end, system);
        }

        template <>
        void Convert(float* value) { 
            *value = wcstof(m_buffer, &m_end);
        }
};

#endif
