#ifndef INPUT_FEEDBACK_NOTIFIER
#define INPUT_FEEDBACK_NOTIFIER

#include "input/feedback/feedback.h"
#include "common/types.h"
#include "screen/matrix/tools.h"

class Notifier {
    private:
        byte m_status_line;

        Layer* Notifier :: Focus();
        void Interrupt(std::wstring message);

    public:
        void Defaults();
        bool Chain(Feedback* status);
};

#endif
