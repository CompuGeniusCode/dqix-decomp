#include <globaldefs.h>
struct Slots02083834 { unsigned char pad[0x454]; short slots[8]; };
// USA: func_02083834
ARM void InsertIntoEmptySlot02083834(struct Slots02083834* s, int value) {
    int i;
    if (value < 0) {
        return;
    }
    for (i = 0; i < 8; i++) {
        if (s->slots[i] < 0) {
            s->slots[i] = value;
            return;
        }
    }
}
