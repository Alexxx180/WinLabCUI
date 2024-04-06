#include "input/feedback/notifier.h"

#include "input/feedback/feedback.h"
#include "screen/matrix/tools/layers.h"
#include "screen/interaction/interaction.h"

Layer* Notifier :: Focus() {
    return out->Target(m_status_line)->Move()->Clear()->Move();
}

void Notifier :: Defaults() {
    m_status_line = FOOT;
}

void Notifier :: Interrupt(std::wstring message) {
    Focus()->Text(message);
    Next();
    Focus()->Clip("status_forward");
}

bool Notifier :: Chain(Feedback* status) {
    if (status->Denied)
        Interrupt(status->Error);
    return status->Denied;
}
