#ifndef INPUT_FEEDBACK_STRING
#define INPUT_FEEDBACK_STRING

#include <string>
#include <iostream>

#include "task/forms/defaults/io/input.h"

class StringPrompt : public Typer {
    private:
        std::wstring m_result;

        Feedback Overflow() {
            std::cin >> m_result;

            Feedback input(m_result.size() > MAX_BUFFER);
            if (input.Denied)
                input.Error = errors.at("overflow") + MaxBufferNumber();

            return input;
        }

        Feedback Empty() {
            return { m_result.empty(), errors.at("empty_string") };
        }

    public:
        const std::wstring& result = m_result;
        Notifier status;

        void Type() {
            bool denied = status.Chain(&Overflow()) || status.Chain(&Empty());
            m_verified = !denied;
        }
}

#endif
