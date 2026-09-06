#include <globaldefs.h>

struct Slot_021dae60 {
    char unk[0x4c];
    int id;
    char rest[0x448 - 0x4c - 4];
};

struct Container_021dae60 {
    char unk[0x958];
    struct Slot_021dae60 slots[4];
};

// USA: func_ov026_021dae60
ARM void* FindSlotById_021dae60(struct Container_021dae60* c, int id) {
    int valid = (id >= 0 && id <= 3);
    if (!valid) {
        goto fail;
    }
    for (int i = 0; i < 4; i++) {
        if (c->slots[i].id == id) {
            return &c->slots[i];
        }
    }
fail:
    return NULL;
}
