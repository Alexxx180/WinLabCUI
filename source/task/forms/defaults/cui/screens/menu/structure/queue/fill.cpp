#include "task/forms/defaults/cui/screens/menu/structure/queue/fill.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/queue.h"

MenuItem QueueFillMenu() {
    MenuItem queue, q[3];
    q[0].SetCommand(new Label("menu_fill_randomized"), QueueRandomized);
    q[1].SetCommand(new Label("menu_queue_from_two"), QueueFromTwo);
    q[2].SetCommand(new Label("menu_fill_reset"), QueueReset);

    queue.SetItems(new Label("menu_queue"))->Vertical(true);
    for (char i = 0; i < 3; i++) queue.Add(&q[i]);
    return queue;
}
