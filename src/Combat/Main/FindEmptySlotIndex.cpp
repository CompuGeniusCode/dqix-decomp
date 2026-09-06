#include <globaldefs.h>

struct SlotArray_0203e03c {
    char unk[0xC];
    int slots[0x20];
};

// USA: func_0203e03c
ARM int FindEmptySlotIndex(struct SlotArray_0203e03c* obj) {
    int i;
    for (i = 0; i < 0x20; i++) {
        if (obj->slots[i] == 0) {
            return i;
        }
    }
    return -1;
}
