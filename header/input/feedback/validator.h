#ifndef INPUT_FEEDBACK_VALIDATOR
#define INPUT_FEEDBACK_VALIDATOR

#include "input/processing/converter.h"
#include "input/processing/reader.h"
#include "input/limiting/buffer.h"

template<typename TYPE>
class Validator {
    private:
        Reader m_parser;
        Converter<TYPE> m_processor;
        wchar_t m_buffer[ACTUAL_MAX];
        TYPE* m_result;

    public:
        Validator();
        short Validate();

        void SetResult(TYPE* result) { m_result = result; }
};

#endif
