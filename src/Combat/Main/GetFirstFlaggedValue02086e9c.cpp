#include <globaldefs.h>

struct FlaggedEntry02086e9c {
    signed char value : 6;
    unsigned char : 1;
    unsigned char flag : 1;
    char rest[0x23c - 1];
};

struct FlaggedEntryContainer02086e9c {
    char pad0[0xf80];
    struct FlaggedEntry02086e9c elems[13];
    unsigned char count;
};

// USA: func_02086e9c
ARM int GetFirstFlaggedValue02086e9c(struct FlaggedEntryContainer02086e9c* c) {
    unsigned char i;
    for (i = 0; i < c->count; i++) {
        struct FlaggedEntry02086e9c* e = &c->elems[i];
        if (e->flag) {
            return e->value;
        }
    }
    return -1;
}
