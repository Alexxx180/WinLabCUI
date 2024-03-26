#include "input/feedback/notifier.h"
#include "screen/drawing/types/layers.h"

void Notifier :: Notify(std::string message) {
    layer->Target(m_server);
    out->Move()->Clear()->Move();
    (pen->*m_signal)(message);
}

void Notifier :: Server(short server) {
    m_server = server;
}

void Notifier :: Signal(Pen::quoteptr signal) {
    m_signal = signal;
}

void Notifier :: Defaults() {
    Server(FOOT);
    Signal(pen->Feedback());
}
