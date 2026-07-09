#include <globaldefs.h>

struct KeyedList0207cb38 {
    char pad0[0xbd0];
    short* valueArrays[8];      // 0xbd0
    signed char* byteArrays[8]; // 0xbf0
    short counts[8];            // 0xc10
    unsigned char keys[8];      // 0xc20
};

// USA: func_0207cb38
ARM int SetEntryInKeyedList0207cb38(struct KeyedList0207cb38* base, int index, int key, int value, char extra) {
    int slot;
    int i;
    short count;
    signed char* bytes;
    short* values;
    if (value < 0) {
        return 0;
    }
    if (extra < 0 || extra > 99) {
        return 0;
    }
    slot = -1;
    for (i = 0; i < 8; i++) {
        if (key == base->keys[i]) {
            slot = i;
            break;
        }
    }
    if (slot == -1) {
        return 0;
    }
    count = base->counts[slot];
    if (index < 0 || index >= count) {
        return 0;
    }
    bytes = base->byteArrays[slot];
    values = base->valueArrays[slot];
    values[index] = value;
    bytes[index] = extra;
    return 1;
}
