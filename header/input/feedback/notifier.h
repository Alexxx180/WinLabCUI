#ifndef INPUT_FEEDBACK_NOTIFIER
#define INPUT_FEEDBACK_NOTIFIER

#include <string>
#include "screen/matrix/pen.h"

class Notifier {
    private:
        short m_server;
        Pen::quoteptr m_signal;

    public:
        void Notify(std::string message);
        void Server(short server);
        void Signal(Pen::quoteptr signal);
        void Defaults();
};

#endif
