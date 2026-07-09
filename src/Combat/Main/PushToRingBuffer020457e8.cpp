#include <globaldefs.h>

struct RingBuffer020457e8 {
    char unk0[0x186c];
    int slots[4];
    char unk187c[0x131];
    signed char cursor;
};

// USA: func_020457e8
ARM void PushToRingBuffer020457e8(struct RingBuffer020457e8* rb, int value) {
    rb->slots[rb->cursor] = value;
    rb->cursor = rb->cursor + 1;
    rb->cursor = rb->cursor % 4;
}
