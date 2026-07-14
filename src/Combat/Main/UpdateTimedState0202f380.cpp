#include <globaldefs.h>

struct TimedState0202f380 { char pad[8]; int state; char pad2[8]; int timer; };

// USA: func_0202f380
ARM void UpdateTimedState0202f380(void* obj, int amount) {
    TimedState0202f380* state = *(TimedState0202f380**)((char*)obj + 0x440);
    if (amount == 0) amount = 1;
    if (state == 0) return;
    switch (state->state) {
    case 1:
        state->state = 2;
        (*(TimedState0202f380**)((char*)obj + 0x440))->timer = 0x1000;
        break;
    case 3:
        state->timer -= amount * 0x199;
        if ((*(TimedState0202f380**)((char*)obj + 0x440))->timer <= 0) {
            (*(TimedState0202f380**)((char*)obj + 0x440))->state = 0;
            (*(TimedState0202f380**)((char*)obj + 0x440))->timer = 0;
        }
        break;
    case 0:
    case 2:
    default:
        return;
    }
}
