#include <globaldefs.h>

struct Sub02184a84 {
    char pad[0xbc];
    unsigned short flagA;
    unsigned short flagB;
};

struct Node02184a84 {
    char pad0[0x1b4];
    int (**table)(void*);
};

// USA: func_ov011_02184a84
ARM void DispatchByFlagAOrB_02184a84(struct Node02184a84* obj) {
    struct Sub02184a84* sub = (struct Sub02184a84*)((char*)obj + 0x100);
    unsigned short idx = sub->flagA;
    if (idx != 0) {
        int r = obj->table[idx](obj);
        if (r == 0) {
            ((struct Sub02184a84*)((char*)obj + 0x100))->flagA = 0;
        }
        return;
    }
    idx = sub->flagB;
    if (idx == 0) return;
    obj->table[idx](obj);
}
