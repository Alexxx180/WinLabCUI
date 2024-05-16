#include "task/forms/defaults/cui/screens/menu/structure/queue/fill.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/queue.h"

MenuItem FillMenu() {
    MenuItem queue, q[3];
    q[0].SetCommand(new Label("menu_fill_randomized"), Randomized);
    q[1].SetCommand(new Label("menu_queue_from_two"), FromTwo);
    q[2].SetCommand(new Label("menu_fill_reset"), Reset);

    queue.SetItems(new Label("menu_queue"));
    for (char i = 0; i < 3; i++) queue.Add(&q[i]);
    return queue;
}
