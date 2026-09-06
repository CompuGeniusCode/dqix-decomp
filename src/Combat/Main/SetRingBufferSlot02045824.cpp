#include <globaldefs.h>

struct RingBuffer02045824 {
    char unk0[0x186c];
    int slots[4];
};

// USA: func_02045824
ARM void SetRingBufferSlot02045824(struct RingBuffer02045824* rb, int value, int index) {
    int i;
    if (index == -1) {
        for (i = 0; i < 4; i++) {
            rb->slots[i] = value;
        }
    } else {
        rb->slots[index] = value;
    }
}
