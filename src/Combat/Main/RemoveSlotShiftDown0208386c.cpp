#include <globaldefs.h>
struct Slots0208386c { unsigned char pad[0x454]; short slots[8]; };
// USA: func_0208386c
ARM void RemoveSlotShiftDown0208386c(struct Slots0208386c* s, int idx) {
    if (idx < 0) return;
    if (idx >= 8) return;
    s->slots[idx] = -1;
    for (; idx < 7; idx++) {
        s->slots[idx] = s->slots[idx + 1];
        s->slots[idx + 1] = -1;
    }
}
