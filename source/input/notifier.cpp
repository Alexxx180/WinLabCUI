#include "input/feedback/notifier.h"
#include "screen/art/types/layers.h"

void Notifier :: Notify(std::string message) {
    Pen::ink().Target(m_server);
    (Pen::ink().*m_signal)(message);
}

Notifier* Notifier Server(short server) {
    m_server = server;
    return this;
}

void Notifier :: Signal(Pen::quoteptr signal) {
    m_signal = signal;
}

void Notifier :: Defaults() {
    Server(FOOT)->Signal(Pen::ink().Feedback());
}
