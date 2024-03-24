#include "input/feedback/notifier.h"
#include "screen/drawing/types/layers.h"

void Notifier :: Notify(std::string message) {
    Pen::ink().Target(m_server);
    (Pen::ink().*m_signal)(message);
    //((this)->*(m_internal))()
}

void Notifier :: Server(short server) {
    m_server = server;
}

void Notifier :: Signal(Pen::quoteptr signal) {
    m_signal = signal;
}

void Notifier :: Defaults() {
    Server(FOOT);
    Signal(Pen::ink().Feedback());
}
