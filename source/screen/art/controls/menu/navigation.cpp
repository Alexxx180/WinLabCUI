#include "screen/art/controls/menu/navigation.h"

char Navigation :: Action() { return -1 }
void Navigation :: Previous() {}
void Navigation :: Next() {}
short Navigation :: Choice() { return -1 }

char Navigation :: Query() {
    char code = Select(menu_input_keys);
	//wprintf(L"Code: %i", code);

    switch (code) {
        case ENTER:
            //wprintf(L"B: %i", m_code);
            code = Action();
	        //wprintf(L"A: %i", m_code);
            break;
        case KEY_UP:
        case KEY_LEFT:
        	//wprintf(L"LEFT");
            Previous();
            break;
        case KEY_DOWN:
        case KEY_RIGHT:
    	    //wprintf(L"RIGHT");
            Next();
            break;
        default:
            break;
    }

    return code;
}
