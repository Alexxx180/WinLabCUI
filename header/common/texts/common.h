#ifndef COMMON_TEXTS_COMMON
#define COMMON_TEXTS_COMMON

#include <string>
#include <map>

static std::map<std::string, std::wstring> texts = {
    { "program_header", L"\u041f\u0440\u043e\u0433\u0440\u0430\u043c\u043c\u0430" },
    { "program_name", L"\u0420\u0430\u0441\u0447\u0435\u0442 \u0437\u043d\u0430\u0447\u0435\u043d\u0438\u0439 \u0444\u0443\u043d\u043a\u0446\u0438\u0438 \u0434\u0432\u0443\u0445 \u043f\u0435\u0440\u0435\u043c\u0435\u043d\u043d\u044b\u0445" },
    { "program_description", L"\u0426\u0438\u043a\u043b\u0438\u0447\u0435\u0441\u043a\u043e\u0435 \u0432\u044b\u0447\u0438\u0441\u043b\u0435\u043d\u0438\u0435 \u0437\u043d\u0430\u0447\u0435\u043d\u0438\u044f Z \u043f\u043e \u0444\u0443\u043d\u043a\u0446\u0438\u0438" },
    { "program_finished", L"\u0417\u0430\u0432\u0435\u0440\u0448\u0438\u043b\u0430\u0020\u0441\u0432\u043e\u044e\u0020\u0440\u0430\u0431\u043e\u0442\u0443" },
    { "program_author", L"\u0412\u044b\u043f\u043e\u043b\u043d\u0438\u043b\u0020\u0441\u0442\u0443\u0434\u0435\u043d\u0442\u0020\u0433\u0440\u0443\u043f\u043f\u044b\u0020\u0032\u0030\u0039\u0032\u0437\u0443\u002c\u0020\u0422\u0430\u0442\u0430\u0440\u0438\u043d\u0446\u0435\u0432\u0020\u0410\u043b\u0435\u043a\u0441\u0430\u043d\u0434\u0440" },
    { "input_header", L"\u0412\u0432\u0435\u0434\u0438\u0442\u0435" },
    { "input_message", L"\u0417\u043d\u0430\u0447\u0435\u043d\u0438\u044f\u0020\u043f\u0435\u0440\u0435\u043c\u0435\u043d\u043d\u044b\u0445 Hx, X\u043d\u0430\u0447, X\u043a\u043e\u043d, Hy, Y\u043d\u0430\u0447, Y\u043a\u043e\u043d" },
    { "input_count", L"\u0420\u0430\u0441\u0447\u0435\u0442 \u043a\u043e\u043b\u0438\u0447\u0435\u0441\u0442\u0432\u0430 \u043e\u043f\u0435\u0440\u0430\u0446\u0438\u0439" },
    { "input_results_overflow", L"\u0420\u0435\u0437\u0443\u043b\u044c\u0442\u0430\u0442 \u0432\u044b\u0445\u043e\u0434\u0438\u0442 \u0437\u0430 \u0440\u0430\u043c\u043a\u0438 \u0434\u043e\u043f\u0443\u0441\u0442\u0438\u043c\u043e\u0433\u043e \u0434\u0438\u0430\u043f\u0430\u0437\u043e\u043d\u0430" },
    { "input_x_step", L"\u0428\u0430\u0433 Hx" },
    { "input_x_start", L"\u0421\u0442\u0430\u0440\u0442 X\u043d\u0430\u0447" },
    { "input_x_end", L"\u0424\u0438\u043d\u0438\u0448 X\u043a\u043e\u043d" },
    { "input_y_step", L"\u0428\u0430\u0433 Hy" },
    { "input_y_start", L"\u0421\u0442\u0430\u0440\u0442 Y\u043d\u0430\u0447" },
    { "input_y_end", L"\u0424\u0438\u043d\u0438\u0448 Y\u043a\u043e\u043d" },
    { "input_assert", L"\u002d\u002d\u002d\u002d\u002d\u003e\u0020\u0412\u044b\u0020\u0432\u0432\u0435\u043b\u0438\u003a %i\n" },
    { "status_exit_esc", L"ESC - \u0432\u044b\u0445\u043e\u0434" },
    { "status_page_home", L"Home - \u0432 \u043d\u0430\u0447\u0430\u043b\u043e" },
    { "status_page_up", L"Page Up - \u0432\u0432\u0435\u0440\u0445" },
    { "status_page_down", L"Page Down - \u0432\u043d\u0438\u0437" },
    { "status_page_end", L"End - \u0432 \u043a\u043e\u043d\u0435\u0446" },
    { "status_pages", L"\u0412\u044b\u0432\u043e\u0434: " },
    { "status_error", L"\u041e\u0448\u0438\u0431\u043a\u0430\u0020\u0432\u0432\u043e\u0434\u0430\u0020\u0434\u0430\u043d\u043d\u044b\u0445\u0021 ESC - \u043e\u0442\u043c\u0435\u043d\u0430" },
    { "status_invalid_data", L"\u0414\u0430\u043d\u043d\u044b\u0435\u0020\u0432\u043d\u0435\u0020\u0434\u0438\u0430\u043f\u0430\u0437\u043e\u043d\u0430! ESC - \u043e\u0442\u043c\u0435\u043d\u0430" },
    { "status_forward", L"\u0045\u004e\u0054\u0045\u0052\u0020\u002d\u0020\u0434\u0430\u043b\u0435\u0435" },
    { "status_repeat", L"\u0045\u0053\u0043\u0020\u002d\u0020\u043f\u043e\u0432\u0442\u043e\u0440\u002c\u0020\u0045\u004e\u0054\u0045\u0052\u0020\u002d\u0020\u0434\u0430\u043b\u0435\u0435" },
    { "status_invalid_boundary", L"\u041a\u043e\u043d\u0435\u0446\u0020\u043d\u0435\u0020\u0434\u043e\u0441\u0442\u0438\u0436\u0438\u043c! ESC - \u043e\u0442\u043c\u0435\u043d\u0430" },
    { "status_invalid_step", L"\u0428\u0430\u0433\u0020\u043d\u0435\u0020\u043c\u043e\u0436\u0435\u0442\u0020\u0431\u044b\u0442\u044c\u0020\u043c\u0435\u043d\u044c\u0448\u0435\u0020\u0030! ESC - \u043e\u0442\u043c\u0435\u043d\u0430" },
    { "status_exit", L"\u0045\u0053\u0043\u0020\u002d\u0020\u0432\u044b\u0445\u043e\u0434\u002c\u0020\u0045\u004e\u0054\u0045\u0052\u0020\u002d\u0020\u0434\u0430\u043b\u0435\u0435" },
    { "status_anykey", L"\u041d\u0430\u0436\u043c\u0438\u0442\u0435\u0020\u043b\u044e\u0431\u0443\u044e\u0020\u043a\u043b\u0430\u0432\u0438\u0448\u0443" },
    { "answer_1", L"\u0428\u043a\u0430\u0444" },
    { "answer_2", L" \u043f\u0440\u043e\u0439\u0434\u0435\u0442\u0020\u0432\u0020\u0434\u0432\u0435\u0440\u044c\u0020\u043b\u0430\u0431\u043e\u0440\u0430\u0442\u043e\u0440\u0438\u0438" },
    { "misc_negation", L" \u043d\u0435" }
};

/*= {
    { "program_header", L"Программа" },
    { "program_name", L"Проходимость шкафа" },
    { "program_description", L"Пройдет ли прямоугольный шкаф в дверь лаборатории" },
    { "program_finished", L"Завершила свою работу" },
    { "input_header_1", L"Введите" },
    { "input_header_2", L"Введены" },
    { "input_message", L"координаты приземления [0..3000]" },
    { "input_argument_1", L"по оси OX - " },
    { "input_argument_2", L"по оси ОY - " },
    { "input_argument_3", L"радиус площадки [0.1..10.0] - " },
    { "input_assert", L"-----> Вы ввели: %lf\n" },
    { "status_error", L"Ошибка ввода данных! ESC - отмена\n" },
    { "status_forward", L"ENTER - далее" },
    { "status_repeat", L"ESC - повтор, ENTER - далее" },
    { "status_exit", L"ESC - выход, ENTER - далее" },
    { "status_anykey", L"Нажмите любую клавишу" },
    { "error_overflow", L"Ошибка: не вводите больше символов чем %d.\n" },
    { "error_empty", L"Ошибка: введена пустая строка.\n" },
    { "error_char", L"Ошибка: некорректный символ.\n" },
    { "answer_1", L"Шкаф" },
    { "answer_2", L" пройдет в дверь лаборатории" },
    { "misc_negation", L" не" }
};*/

#endif
