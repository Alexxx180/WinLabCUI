#include "input/feedback/notifier.h"

#include "screen/matrix/tools/layers.h"
#include "screen/interaction/interaction.h"

Notifier* Notifier :: Notify(std::string message) {
    layer->Target(m_server);
    out->Move()->Clear()->Move();
    (pen->*m_signal)(message);
    Next();
    return this;
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
