#include <globaldefs.h>

struct Struct5e00 {
    char pad[0x5e00];
    unsigned char count;
    unsigned char flags;
    char pad2[2];
    int values[1];
};

// USA: func_ov000_021673e0
ARM int FindAndSetFreeSlot021673e0(struct Struct5e00* s) {
    int i;
    for (i = 0; i < s->count; i++) {
        if (!(s->flags & (1 << i))) {
            s->flags |= (1 << i);
            return s->values[i];
        }
    }
    return 0;
}
