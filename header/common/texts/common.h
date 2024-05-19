#ifndef COMMON_TEXTS_COMMON
#define COMMON_TEXTS_COMMON

#include <string>
#include <map>

static const std::map<std::string, std::wstring> texts = {
    // Program description
    { "program_header", L"CUI-\u0424\u0440\u0435\u0439\u043c\u0432\u043e\u0440\u043a WinLabCUI" }, // CUI-Фреймворк WinLabCUI
    { "program_name", L"\u041f\u0440\u0435\u0434\u043d\u0430\u0437\u043d\u0430\u0447\u0435\u043d \u0434\u043b\u044f \u0431\u044b\u0441\u0442\u0440\u043e\u0433\u043e \u0441\u043e\u0441\u0442\u0430\u0432\u043b\u0435\u043d\u0438\u044f \u0444\u043e\u0440\u043c \u0432 CLI \u043e\u043a\u0440\u0443\u0436\u0435\u043d\u0438\u0438" }, // Предназначен для быстрого составления форм в CLI окружении
    { "program_description", L"\u0414\u0435\u043c\u043e\u043d\u0441\u0442\u0440\u0430\u0446\u0438\u044f \u0432\u043e\u0437\u043c\u043e\u0436\u043d\u043e\u0441\u0442\u0435\u0439 \u0444\u0440\u0435\u0439\u043c\u0432\u043e\u0440\u043a\u0430:" }, // Демонстрация возможностей фреймворка
    { "program_labs", L"- \u041b\u0430\u0431\u043e\u0440\u0430\u0442\u043e\u0440\u043d\u044b\u0435 \u0438 \u043f\u0440\u0430\u043a\u0442\u0438\u0447\u0435\u0441\u043a\u0438\u0435 \u0440\u0430\u0431\u043e\u0442\u044b" }, // - Лабораторные и практические работы
    { "program_processing", L"- \u041e\u0431\u0440\u0430\u0431\u043e\u0442\u043a\u0430 \u0441\u0442\u0440\u043e\u043a, \u0441\u0442\u0440\u0443\u043a\u0442\u0443\u0440 \u0434\u0430\u043d\u043d\u044b\u0445" }, // - Обработка строк, структур данных
    { "program_language", L"- \u041f\u043e\u0434\u0434\u0435\u0440\u0436\u043a\u0430 \u043c\u0443\u043b\u044c\u0442\u0438\u044f\u0437\u044b\u0447\u043d\u043e\u0441\u0442\u0438" }, // - Поддержка мультиязычности
    { "program_author", L"\u0410\u0432\u0442\u043e\u0440: \u0422\u0430\u0442\u0430\u0440\u0438\u043d\u0446\u0435\u0432 \u0410\u043b\u0435\u043a\u0441\u0430\u043d\u0434\u0440" }, // Автор: Татаринцев Александр

    // Common text
    { "first_input", L"- First Input (FI" },
    { "first_output", L"- First Output FO)" },
    { "max_elements", L"\u041c\u0430\u043a\u0441\u0438\u043c\u0430\u043b\u044c\u043d\u043e\u0435 \u043a\u043e\u043b\u0438\u0447\u0435\u0441\u0442\u0432\u043e \u044d\u043b\u0435\u043c\u0435\u043d\u0442\u043e\u0432 \u0432 \u0440\u0430\u043c\u043a\u0430\u0445 \u0434\u0435\u043c\u043e: 10" }, // Максимальное количество элементов в рамках демо: 10
    { "no_elements", L"\u041d\u0435\u0442 \u044d\u043b\u0435\u043c\u0435\u043d\u0442\u043e\u0432! \u0414\u043b\u044f \u043d\u0430\u0447\u0430\u043b\u0430 \u0440\u0430\u0431\u043e\u0442\u044b \u0432\u044b\u0431\u0435\u0440\u0438\u0442\u0435 \u043e\u043f\u0446\u0438\u044e" }, // Нет элементов! Для начала работы выберите опцию
    { "view", L"\u041f\u0440\u043e\u0441\u043c\u043e\u0442\u0440" }, // Просмотр
    { "work_demo", L"\u0414\u0435\u043c\u043e\u043d\u0441\u0442\u0440\u0430\u0446\u0438\u044f \u0440\u0430\u0431\u043e\u0442\u044b \u0441\u0442\u0440\u0443\u043a\u0442\u0443\u0440\u044b" }, // Демонстрация работы структуры
    { "data_structure", L"\u0421\u0442\u0440\u0443\u043a\u0442\u0443\u0440\u0430 \u0434\u0430\u043d\u043d\u044b\u0445" }, // Структура данных
    { "data_application", L"\u041f\u0440\u0438\u043c\u0435\u043d\u0435\u043d\u0438\u044f:" }, // Применения:
    { "structure_list", L"\u0421\u043f\u0438\u0441\u043e\u043a" }, // Список
    { "structure_queue", L"\u041e\u0447\u0435\u0440\u0435\u0434\u044c" }, // Очередь
    { "structure_stack", L"\u0421\u0442\u0435\u043a" }, // Стек
    { "structure-helper", L"\u041d\u0443\u0436\u0435\u043d \u0442\u0438\u043f-\u043f\u043e\u043c\u043e\u0449\u043d\u0438\u043a \u0434\u043b\u044f \u043f\u0440\u043e\u0441\u043c\u043e\u0442\u0440\u0430" }, // Нужен тип-помощник для просмотра

    // Navigation and status messages
    { "status_error", L"\u041e\u0448\u0438\u0431\u043a\u0430 \u0432\u0432\u043e\u0434\u0430 \u0434\u0430\u043d\u043d\u044b\u0445! [Esc] \u043e\u0442\u043c\u0435\u043d\u0430" }, // Ошибка ввода данных! [Esc] отмена
    { "status_page_home", L"[Home] \u0432 \u043d\u0430\u0447\u0430\u043b\u043e" }, // [Home] в начало
    { "status_page_up", L"[Page Up] \u0432\u0432\u0435\u0440\u0445" }, // [Page Up] вверх
    { "status_page_down", L"[Page Down] \u0432\u043d\u0438\u0437" }, // [Page Down] вниз
    { "status_page_end", L"[End] \u0432 \u043a\u043e\u043d\u0435\u0446" }, // [End] в конец
    { "status_pages", L"\u0412\u044b\u0432\u043e\u0434: " }, // Вывод: 
    { "status_forward", L"[Enter] \u0434\u0430\u043b\u0435\u0435" }, // [Enter] далее
    { "status_repeat", L"[Esc] \u043f\u043e\u0432\u0442\u043e\u0440  [Enter] \u0434\u0430\u043b\u0435\u0435" }, // [Esc] повтор  [Enter] далее
    { "status_exit", L"[Esc] \u043e\u0431\u0440\u0430\u0442\u043d\u043e  [Enter] \u0434\u0430\u043b\u0435\u0435" }, // [Esc] обратно  [Enter] далее
    { "status_anykey", L"\u041d\u0430\u0436\u043c\u0438\u0442\u0435 \u043b\u044e\u0431\u0443\u044e \u043a\u043b\u0430\u0432\u0438\u0448\u0443" }, // Нажмите любую клавишу
    { "status_menu_navigation", L"[\u2190\u2195\u2192] \u043c\u0435\u043d\u044e  [Esc] \u043e\u0431\u0440\u0430\u0442\u043d\u043e  [Enter] \u0432\u044b\u0431\u043e\u0440" }, // [←↕→] меню  [Esc] обратно  [Enter] выбор
    { "status_confirm_exit", L"\u0423\u0432\u0435\u0440\u0435\u043d\u044b \u0447\u0442\u043e \u0445\u043e\u0442\u0438\u0442\u0435 \u0432\u044b\u0439\u0442\u0438? [Enter] \u0414\u0430  [Esc] \u041d\u0435\u0442" }, // L"Уверены что хотите выйти? [Enter] Да  [Esc] Нет

    // Menu options - Common
    { "menu_fill_randomized", L"\u2666 \u0413\u0435\u043d\u0435\u0440\u0430\u0446\u0438\u044f" }, // ♦ Генерация
    { "menu_fill_reset", L"\u2666 \u0421\u0431\u0440\u043e\u0441" }, // ♦ Сброс
    { "menu_operations", L"\u25b6 \u041e\u043f\u0435\u0440\u0430\u0446\u0438\u044f" }, // ▶ Операция
    { "menu_operations_view", L"\u25b6 \u041f\u0440\u043e\u0441\u043c\u043e\u0442\u0440" }, // ▶ Просмотр
    { "menu_operations_search", L"\u2666 \u041f\u043e\u0438\u0441\u043a" }, // ♦ Поиск
    { "menu_operations_add", L"\u2666 \u0414\u043e\u0431\u0430\u0432\u043b\u0435\u043d\u0438\u0435" }, // ♦ Добавление
    { "menu_operations_add_recurse", L"\u25b6 \u0414\u043e\u0431\u0430\u0432\u043b\u0435\u043d\u0438\u0435" }, // ▶ Добавление
    { "menu_operations_delete", L"\u2666 \u0423\u0434\u0430\u043b\u0435\u043d\u0438\u0435" }, // ♦ Удаление
    { "menu_operations_delete_recurse", L"\u25b6 \u0423\u0434\u0430\u043b\u0435\u043d\u0438\u0435" }, // ▶ Удаление
    { "menu_first", L"\u25b6 \u041d\u0430\u0447\u0430\u043b\u043e" }, // ♦ Начало
    { "menu_before", L"\u25b6 \u0414\u043e" }, // ♦ До
    { "menu_after", L"\u25b6 \u041f\u043e\u0441\u043b\u0435" }, // ♦ После
    { "menu_last", L"\u25b6 \u041a\u043e\u043d\u0435\u0446" }, // ♦ Конец
    { "menu_navigation", L"\u2666 \u0412\u044b\u0445\u043e\u0434" }, // ▶ Навигация
    { "menu_back", L"\u2666 \u0412\u044b\u0445\u043e\u0434" }, // ♦ Обратно
    { "menu_exit", L"\u2666 \u0412\u044b\u0445\u043e\u0434" }, // ♦ Выход

    // Menu options - Main
    { "menu_structure", L"\u25b6 \u0421\u0442\u0440\u0443\u043a\u0442\u0443\u0440\u044b" }, // ▶ Структуры
    { "menu_structure_list", L"\u2666 \u0421\u043f\u0438\u0441\u043e\u043a" }, // ♦ Список
    { "menu_structure_queue", L"\u2666 \u041e\u0447\u0435\u0440\u0435\u0434\u044c" }, // ♦ Очередь
    { "menu_structure_stack", L"\u2666 \u0421\u0442\u0435\u043a" }, // ♦ Стек
    { "menu_stack_minimal", L"\u2666 \u041c\u0438\u043d\u0438\u043c\u0443\u043c" }, // ♦ Минимум
    { "menu_task_split", L"\u2666 \u0420\u0430\u0437\u0434\u0435\u043b\u0435\u043d\u0438\u0435" }, // ♦ Разделение
    { "menu_practice", L"\u25b6 \u041f\u0440\u0430\u043a\u0442\u0438\u043a\u0430" }, // ▶ Практика
    { "menu_practice_string", L"\u2666 \u0421\u0442\u0440\u043e\u043a\u0438" }, // ♦ Строки
    { "menu_practice_structure", L"\u25b6 \u0421\u0442\u0440\u0443\u043a\u0442\u0443\u0440\u0430" }, // ▶ Структура
    { "menu_practice_structure_filter", L"\u2666 \u0424\u0438\u043b\u044c\u0442\u0440" }, // ♦ Фильтр
    { "menu_practice_file", L"\u25b6 \u0424\u0430\u0439\u043b\u044b" }, // ▶ Файлы
    { "menu_practice_file_text", L"\u25b6 \u0422\u0435\u043a\u0441\u0442\u043e\u0432\u044b\u0439" }, // ▶ Текстовый
    { "menu_practice_file_text_word", L"\u2666 \u0421\u043b\u043e\u0432\u043e" }, // ♦ Слово
    { "menu_practice_file_text_number", L"\u2666 \u0427\u0438\u0441\u043b\u0430" }, // ♦ Числа
    { "menu_practice_file_binary", L"\u2666 \u0414\u0432\u043e\u0438\u0447\u043d\u044b\u0439" }, // ♦ Двоичный
    { "menu_practice_records_week_monday", L"\u25c0 \u041f\u043e\u043d\u0435\u0434\u0435\u043b\u044c\u043d\u0438\u043a \u25b6" }, // ◀ Понедельник ▶ 
    { "menu_practice_records_week_tuesday", L"\u25c0 \u0412\u0442\u043e\u0440\u043d\u0438\u043a \u25b6" }, // ◀ Вторник ▶ 
    { "menu_practice_records_week_wednesday", L"\u25c0 \u0421\u0440\u0435\u0434\u0430 \u25b6" }, // ◀ Среда ▶ 
    { "menu_practice_records_week_thursday", L"\u25c0 \u0427\u0435\u0442\u0432\u0435\u0440\u0433 \u25b6" }, // ◀ Четверг ▶ 
    { "menu_practice_records_week_friday", L"\u25c0 \u041f\u044f\u0442\u043d\u0438\u0446\u0430 \u25b6" }, // ◀ Пятница ▶ 
    { "menu_practice_records_week_saturday", L"\u25c0 \u0421\u0443\u0431\u0431\u043e\u0442\u0430 \u25b6" }, // ◀ Суббота ▶ 
    { "menu_practice_records_week_sunday", L"\u25c0 \u0412\u043e\u0441\u043a\u0440\u0435\u0441\u0435\u043d\u044c\u0435 \u25b6" }, // ◀ Воскресенье ▶ 

    // Menu options - List
    { "menu_list", L"\u25b6 \u0421\u043f\u0438\u0441\u043e\u043a" }, // ▶ Список
    { "menu_list_ordered", L"\u2666 \u041f\u043e \u043f\u043e\u0440\u044f\u0434\u043a\u0443" }, // ♦ По порядку
    { "menu_list_medium", L"\u2666 \u0421\u0440\u0435\u0434\u043d\u0435\u0435" }, // ♦ Среднее

    // Menu options - Queue
    { "menu_queue", L"\u25b6 \u041e\u0447\u0435\u0440\u0435\u0434\u044c" }, // ▶ Очередь
    { "menu_queue_from_two", L"\u25b6 \u0418\u0437\u0020\u0434\u0432\u0443\u0445" }, // ▶ Из двух

    // Menu options - Stack
    { "menu_stack", L"\u25b6 \u0421\u0442\u0435\u043a" }, // ▶ Стек

    // Structure qualities
    { "list_sequence", L"- \u041a\u043e\u043d\u0435\u0447\u043d\u0430\u044f \u043f\u043e\u0441\u043b\u0435\u0434\u043e\u0432\u0430\u0442\u0435\u043b\u044c\u043d\u043e\u0441\u0442\u044c" }, // - Конечная последовательность
    { "list_value_pack", L"- \u0423\u043f\u043e\u0440\u044f\u0434\u043e\u0447\u0435\u043d\u043d\u044b\u0439 \u043d\u0430\u0431\u043e\u0440 \u0437\u043d\u0430\u0447\u0435\u043d\u0438\u0439" }, // - Упорядоченный набор значений
    { "list_data_length", L"- \u0414\u0430\u043d\u043d\u044b\u0435 \u0440\u0430\u0437\u043d\u043e\u0433\u043e \u0440\u0430\u0437\u043c\u0435\u0440\u0430" }, // - Данные разного размера
    { "list_enum", L"- \u041f\u0435\u0440\u0435\u0447\u0438\u0441\u043b\u0435\u043d\u0438\u044f" }, // - Перечисления
    { "queue_events", L"- \u041e\u0440\u0433\u0430\u043d\u0438\u0437\u0430\u0446\u0438\u044f \u0441\u043e\u0431\u044b\u0442\u0438\u0439" }, // - Организация событий
    { "queue_buffer", L"- \u041a\u043b\u0430\u0432\u0438\u0430\u0442\u0443\u0440\u043d\u044b\u0439 \u0431\u0443\u0444\u0435\u0440" }, // - Клавиатурный буфер
    { "stack_transactions", L"- \u041f\u043e\u0434\u0434\u0435\u0440\u0436\u043a\u0430 \u0442\u0440\u0430\u043d\u0437\u0430\u043a\u0446\u0438\u0439" }, // - Поддержка транзакций
    { "stack_calls", L"- \u0425\u0440\u0430\u043d\u0435\u043d\u0438\u0435 \u0441\u0438\u0441\u0442\u0435\u043c\u043d\u044b\u0445 \u0432\u044b\u0437\u043e\u0432\u043e\u0432" }, // - Хранение системных вызовов,
    { "strings_replacement", L"\u0417\u0430\u043c\u0435\u043d\u0430 \u0441\u0442\u0440\u043e\u043a\u0438" }, // Замена строки
    { "strings_replacement_original", L"\u043e\u0440\u0438\u0433\u0438\u043d\u0430\u043b: " }, // оригинал:
    { "strings_replacement_result", L"\u0438\u0437\u043c\u0435\u043d\u0435\u043d\u0430: " },   // изменена:
    { "strings_sorted_words", L"\u0421\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u0430\u043d\u043d\u044b\u0435 \u0441\u043b\u043e\u0432\u0430" }, // Сортированные слова
    { "records_weekly", L"\u0417\u0430\u043f\u0438\u0441\u0438 \u043f\u043e \u0434\u043d\u044e \u043d\u0435\u0434\u0435\u043b\u0438" }, // Записи по дню недели
};

#endif
