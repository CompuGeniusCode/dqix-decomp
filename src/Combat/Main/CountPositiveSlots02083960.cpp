#include <globaldefs.h>
struct Slots02083960 { unsigned char pad[0x454]; short slots[8]; };
// USA: func_02083960
ARM int CountPositiveSlots02083960(struct Slots02083960* s) {
    int count = 0;
    int i;
    for (i = 0; i < 8; i++) {
        if (s->slots[i] > 0) {
            count++;
        }
    }
    return count;
}
