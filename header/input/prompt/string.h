#ifndef INPUT_FEEDBACK_STRING
#define INPUT_FEEDBACK_STRING

#include <string>
#include <iostream>

#include "input/feedback/limiting/buffer.h"
#include "input/feedback/feedback.h"
#include "input/feedback/notifier.h"
#include "input/feedback/typer.h"

class StringPrompt : public Typer {
    private:
        std::wstring m_result;

        Feedback Overflow() {
            std::wcin >> m_result;

            Feedback input(m_result.size() > MAX_BUFFER);
            if (input.Denied)
                input.Error = errors.at("overflow") + SMAX_BUFFER;

            return input;
        }

        Feedback Empty() {
            Feedback input(m_result.empty());
            input.Error = errors.at("empty_string");
            return input;
        }

    public:
        const std::wstring& result = m_result;
        Notifier status;

        void Type() {
            bool denied = status.Chain(&Overflow()) || status.Chain(&Empty());
            m_verified = !denied;
        }
};

#endif
