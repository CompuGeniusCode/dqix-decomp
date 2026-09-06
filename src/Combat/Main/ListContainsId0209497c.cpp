#include <globaldefs.h>

struct Entry0209497c {
    char pad0[0x30];
    short id;                       // 0x30
    char pad32[0x34 - 0x32];
};

struct List0209497c {
    struct Entry0209497c entries[18];   // 0..0x3a7
    char pad[0x3cb - 0x3a8];            // 0x3a8..0x3ca
    signed char count;                  // 0x3cb
};

// USA: func_0209497c
ARM int ListContainsId0209497c(struct List0209497c* s, int key) {
    int i;
    for (i = 0; i < s->count; i++) {
        short id = s->entries[i].id;
        if (id == key) {
            return 1;
        }
    }
    return 0;
}
