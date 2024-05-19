#include "task/forms/defaults/cui/screens/templates/list.h"
#include "screen/matrix/tools.h"

void ListInfo() {
    out->Target(MAIN)->Page(0)->Line(0)->Size(2);
    out->Move()->Clip("work_demo")->Line();
    out->Move()->Clip("view")->Page(1);
    out->Move()->Clip("menu_structure_list")->Line();
    out->Move()->Clip("list_sequence")->Line();
    out->Move()->Clip("list_value_pack")->Line();
    out->Move()->Clip("data_application")->Line();
    out->Move()->Clip("list_data_length")->Line();
    out->Move()->Clip("list_enum")->Page(0)->Line(1);
}
