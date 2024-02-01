#define SCREEN_ART_CONTROLS_MENU
#define SCREEN_ART_CONTROLS_MENU

#include <vector>

class MenuItem {
    private:
       

        void (*m_command)() = NULL;

        void Expand() {
            
        }

    public:
        std::vector<MenuItem>* Items = NULL;
        Option* Parameters = NULL;

        void Minimize() {

        }

        

        
        void SetItems() {
            
        }

        void Focus() {
            
        }

bool SelectMenuOption() {
    bool is_exit = false;

    switch (current_menu_option) {
        case 0:
            current_menu_option = -1;
            Await(ArrayMenuLoop(), ESC);
            break;
        case 1:
            is_exit = Select(ESC, ENTER) == ENTER;
            break;
        default:
            array_options[current_menu_option].Next();
            break;
    }

    return is_exit;
}

bool MenuLoop() {
    char code = Select(menu_input_keys);
    bool is_exit = false;

    switch (code) {
        case ENTER: is_exit = SelectMenuOption(); break;
        case KEY_LEFT:
            NavigateMenuOption(main_menu, -1);
            break;
        case KEY_RIGHT:
            NavigateMenuOption(main_menu, 1);
            break;
        default: break;
    };

    return is_exit;
}

}

#endif
