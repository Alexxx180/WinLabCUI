#include "task/forms/defaults/cui/screens/templates/list.h"
#include "screen/matrix/tools.h"

void QueueInfo() {
    out->Target(MAIN)->Page(0)->Line(0)->Size(2);
    out->Move()->Clip("work_demo")->Line();
    out->Move()->Clip("view")->Page(1);
    out->Move()->Clip("menu_structure_queue")->Line();
    out->Move()->Clip("first_input")->Line();
    out->Move()->Clip("first_output")->Line();
    out->Move()->Clip("data_application")->Line();
    out->Move()->Clip("queue_events")->Line();
    out->Move()->Clip("queue_buffer")->Page(0)->Line(1);
}
