#ifndef INPUT_FEEDBACK_NOTIFIER
#define INPUT_FEEDBACK_NOTIFIER

#include <string>

#include "screen/matrix/pen.h"
#include "screen/art/types/layers.h"

class Notifier {
private:
    short m_server;
    Pen::quoteptr m_signal;

public:
    void Notify(std::string message) {
        Pen::ink().Target(m_server);
        (Pen::ink().*m_signal)(message);
    }

    Notifier* Server(short server) {
        m_server = server;
        return this;
    }

    Notifier* Signal(Pen::quoteptr signal) {
        m_signal = signal;
        return this;
    }

    void Defaults() {
        Server(FOOT)->Signal(Pen::ink().Feedback());
    }
};

#endif
