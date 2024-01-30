#ifndef INPUT_FEEDBACK_NOTIFIER
#define INPUT_FEEDBACK_NOTIFIER

#include <string>
#include "output/format/pen.h"

class Notifier {
private:
    short m_server;
    Pen* (Pen::*m_signal)(std::string) = NULL;

public:
    void Notify(std::string message) {
        Pen::ink().Target(m_server);
        (Pen::ink().*m_signal)(message);
    }

    Notifier* Server(short server) {
        m_server = server;
        return this;
    }

    Notifier* Signal(Pen* (Pen::*signal)(std::string)) {
        m_signal = signal;
        return this;
    }
};

#endif
