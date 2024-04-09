#ifndef INPUT_FEEDBACK_NOTIFIER
#define INPUT_FEEDBACK_NOTIFIER

#include "common/types.h"
#include "input/feedback/feedback.h"
#include "screen/matrix/tools.h"

class Notifier {
    private:
        byte m_status_line;

        Layer* Notifier :: Focus();
        void Interrupt(std::wstring message);

    public:
        Notifier();
        bool Chain(Feedback* status);
};

#endif
