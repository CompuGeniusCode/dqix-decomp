#include <globaldefs.h>

struct Entry020949bc {
    short id;                       // 0x0
    char pad[0x34 - 2];
};

struct List020949bc {
    char pad0[0x1d0];               // 0..0x1cf
    struct Entry020949bc entries[9];    // 0x1d0..0x3a3
    char pad2[0x3cc - 0x3a4];           // 0x3a4..0x3cb
    signed char count;                  // 0x3cc
};

// USA: func_020949bc
ARM int ListContainsId020949bc(struct List020949bc* s, int key) {
    int i;
    for (i = 0; i < s->count; i++) {
        short id = s->entries[i].id;
        if (id == key) {
            return 1;
        }
    }
    return 0;
}
