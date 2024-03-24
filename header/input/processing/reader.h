#ifndef INPUT_PROCESSING_READER
#define INPUT_PROCESSING_READER

#include "input/limiting/buffer.h"

class Reader {
    private:
        wchar_t* m_buffer;
        size_t m_length;

    public:
        bool NotReadable();
        bool IsOverflow();
        bool IsEmpty();
        void SetBuffer(wchar_t buffer[ACTUAL_MAX]);
};

#endif
