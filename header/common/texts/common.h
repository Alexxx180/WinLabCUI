#ifndef COMMON_TEXTS_COMMON
#define COMMON_TEXTS_COMMON

#include <string>
#include <map>

static std::map<std::string, std::wstring> texts = {
    { "program_header", L"\u041f\u0440\u043e\u0433\u0440\u0430\u043c\u043c\u0430" },
    { "program_name", L"\u0421\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u043a\u0430 \u043c\u0430\u0441\u0441\u0438\u0432\u043e\u0432 \u0438 \u043e\u0446\u0435\u043d\u043a\u0430 \u043f\u0440\u043e\u0438\u0437\u0432\u043e\u0434\u0438\u0442\u0435\u043b\u044c\u043d\u043e\u0441\u0442\u0438" },
    { "program_description", L"\u0421\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u043a\u0438: \u043f\u0440\u044f\u043c\u043e\u0433\u043e \u0432\u044b\u0431\u043e\u0440\u0430, \u0432\u0441\u0442\u0430\u0432\u043a\u0430\u043c\u0438, \u0425\u043e\u0430\u0440\u0430, \u0441 \u0440\u0435\u043a\u0443\u0440\u0441\u0438\u0435\u0439 \u0438 \u0431\u0435\u0437" },
    { "program_finished", L"\u0417\u0430\u0432\u0435\u0440\u0448\u0438\u043b\u0430 \u0441\u0432\u043e\u044e \u0440\u0430\u0431\u043e\u0442\u0443" },
    { "program_author", L"\u0412\u044b\u043f\u043e\u043b\u043d\u0438\u043b \u0441\u0442\u0443\u0434\u0435\u043d\u0442 \u0433\u0440\u0443\u043f\u043f\u044b \u0032\u0030\u0039\u0032\u0437\u0443\u002c \u0422\u0430\u0442\u0430\u0440\u0438\u043d\u0446\u0435\u0432 \u0410\u043b\u0435\u043a\u0441\u0430\u043d\u0434\u0440" },
    { "input_header", L"\u0412\u0432\u0435\u0434\u0438\u0442\u0435" },
    { "input_operation", L"\u0412\u044b\u0431\u0435\u0440\u0438\u0442\u0435 \u043e\u043f\u0435\u0440\u0430\u0446\u0438\u044e \u0438\u0437 \u043c\u0435\u043d\u044e '\u041c\u0430\u0441\u0441\u0438\u0432'" },
    { "input_array_dimension", L"\u0420\u0430\u0437\u043c\u0435\u0440\u043d\u043e\u0441\u0442\u044c \u043c\u0430\u0441\u0441\u0438\u0432\u0430" },
    { "input_value_edit_1", L"\u0417\u043d\u0430\u0447\u0435\u043d\u0438\u0435 '" },
    { "input_value_edit_2", L"' \u0438\u0437\u043c\u0435\u043d\u0435\u043d\u043e: " },
    { "input_array_elements", L"\u042d\u043b\u0435\u043c\u0435\u043d\u0442\u044b \u043c\u0430\u0441\u0441\u0438\u0432\u0430" },
    { "input_results", L"\u0420\u0435\u0437\u0443\u043b\u044c\u0442\u0430\u0442" },
    { "output_source_array", L"\u0418\u0441\u0445\u043e\u0434\u043d\u044b\u0439" },
    { "output_sorted_array", L"\u0421\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u043a\u0430" },
    { "status_menu_navigation", L"[\u2190\u2195\u2192] \u043c\u0435\u043d\u044e  [Esc] \u043e\u0431\u0440\u0430\u0442\u043d\u043e  [Enter] \u0432\u044b\u0431\u043e\u0440" },
    { "status_confirm_exit", L"\u0423\u0432\u0435\u0440\u0435\u043d\u044b \u0447\u0442\u043e \u0445\u043e\u0442\u0438\u0442\u0435 \u0432\u044b\u0439\u0442\u0438? [Enter] \u0414\u0430  [Esc] \u041d\u0435\u0442" },
	{ "menu_header", L"\u25b6 \u041c\u0435\u043d\u044e" },
	{ "menu_array_sort", L"\u2666 \u0421\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u043a\u0430" },
	{ "menu_individual", L"\u2666 \u0417\u0430\u0434\u0430\u043d\u0438\u0435" },
    { "menu_array", L"\u25bc \u041c\u0430\u0441\u0441\u0438\u0432" },
    { "menu_calculate", L"\u2666 \u0412\u044b\u0447\u0438\u0441\u043b\u0438\u0442\u044c" },
    { "menu_sort_array_hoar", L"\u25c0\ufe0f \u0421\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u043a\u0430 \u0425\u043e\u0430\u0440\u0430 \u25b6\ufe0f" },
    { "menu_sort_array_insertions", L"\u25c0\ufe0f \u0421\u043e\u0440\u0442\u0438\u0440\u043e\u0432\u043a\u0430 \u0432\u0441\u0442\u0430\u0432\u043a\u0430\u043c\u0438 \u25b6\ufe0f" },
    { "menu_sort_array_selection", L"\u25c0\ufe0f \u041f\u0440\u044f\u043c\u043e\u0439 \u0432\u044b\u0431\u043e\u0440 \u25b6\ufe0f" },
    { "menu_array_generation", L"\u0412\u0432\u043e\u0434 \u0434\u0430\u043d\u043d\u044b\u0445" },
    { "menu_array_generation_random", L"\u0421\u043b\u0443\u0447\u0430\u0439\u043d\u044b\u0439" },
    { "menu_array_generation_manual", L"\u0412\u0440\u0443\u0447\u043d\u0443\u044e" },
    { "menu_array_type", L"\u0422\u0438\u043f \u0434\u0430\u043d\u043d\u044b\u0445" },
    { "menu_array_type_numbers", L"\u0427\u0438\u0441\u043b\u0430" },
    { "menu_array_type_strings", L"\u0421\u0442\u0440\u043e\u043a\u0438" },
    { "menu_exit", L"\u2666 \u0412\u044b\u0445\u043e\u0434" },
	{ "individual_source_data", L"\u0418\u0441\u0445\u043e\u0434\u043d\u044b\u0435 \u0434\u0430\u043d\u043d\u044b\u0435" },
	{ "individual_arrays_name", L"\u041c\u0430\u0441\u0441\u0438\u0432" },
	{ "individual_arrays_sum", L"\u0421\u0443\u043c\u043c\u0430 \u044d\u043b\u0435\u043c\u0435\u043d\u0442\u043e\u0432" },
	{ "individual_max_element", L"\u041c\u0430\u043a\u0441\u0438\u043c\u0430\u043b\u044c\u043d\u044b\u0439 \u044d\u043b\u0435\u043c\u0435\u043d\u0442" },
    { "status_page_home", L"[Home] \u0432 \u043d\u0430\u0447\u0430\u043b\u043e" },
    { "status_page_up", L"[Page Up] \u0432\u0432\u0435\u0440\u0445" },
    { "status_page_down", L"[Page Down] \u0432\u043d\u0438\u0437" },
    { "status_page_end", L"[End] \u0432 \u043a\u043e\u043d\u0435\u0446" },
    { "status_pages", L"\u0412\u044b\u0432\u043e\u0434: " },
    { "status_error", L"\u041e\u0448\u0438\u0431\u043a\u0430 \u0432\u0432\u043e\u0434\u0430 \u0434\u0430\u043d\u043d\u044b\u0445! [Esc] \u043e\u0442\u043c\u0435\u043d\u0430" },
    { "status_invalid_data", L"\u0414\u0430\u043d\u043d\u044b\u0435 \u0432\u043d\u0435 \u0434\u0438\u0430\u043f\u0430\u0437\u043e\u043d\u0430! [Esc] \u043e\u0442\u043c\u0435\u043d\u0430" },
    { "status_forward", L"[Enter] \u0434\u0430\u043b\u0435\u0435" },
    { "status_repeat", L"[Esc] \u043f\u043e\u0432\u0442\u043e\u0440\u002c  [Enter] \u0434\u0430\u043b\u0435\u0435" },
    { "status_invalid_boundary", L"\u041a\u043e\u043d\u0435\u0446 \u043d\u0435 \u0434\u043e\u0441\u0442\u0438\u0436\u0438\u043c! [Esc] \u043e\u0442\u043c\u0435\u043d\u0430" },
    { "status_invalid_step", L"\u0428\u0430\u0433 \u043d\u0435 \u043c\u043e\u0436\u0435\u0442 \u0431\u044b\u0442\u044c \u043c\u0435\u043d\u044c\u0448\u0435 0! [Esc] \u043e\u0442\u043c\u0435\u043d\u0430" },
    { "status_exit", L"[Esc] \u043e\u0431\u0440\u0430\u0442\u043d\u043e  [Enter] \u0434\u0430\u043b\u0435\u0435" },
    { "status_anykey", L"\u041d\u0430\u0436\u043c\u0438\u0442\u0435 \u043b\u044e\u0431\u0443\u044e \u043a\u043b\u0430\u0432\u0438\u0448\u0443" }
};

#endif
