#ifndef INPUT_PROCESSING_READER
#define INPUT_PROCESSING_READER

#include "input/feedback/limiting/buffer.h"
#include "input/feedback/feedback.h"

class Reader {
    private:
        wchar_t* m_buffer;
        size_t m_length;

    protected:
        bool NotReadable(std::wstring* text);
        bool IsOverflow(std::wstring* text);
        bool IsEmpty(std::wstring* text);

    public:
        Feedback Interrupt();
        void SetBuffer(wchar_t buffer[ACTUAL_MAX]);
};

#endif
