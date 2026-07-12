#include <globaldefs.h>

struct Struct020478bc {
    char pad0[0xc];
    char* table;
    char pad1[0x14 - 0x10];
    int count;
    char pad2[0x70 - 0x18];
    int field70;
    int index;
    int field78;
    int field7c;
    char pad3[0x84 - 0x80];
    unsigned char flag0 : 1;
    unsigned char restBits : 7;
};

extern int data_02114e50;

// USA: func_020478bc
ARM void RecomputeField0x7c(struct Struct020478bc* o, int newIndex) {
    if (!o->flag0) {
        return;
    }
    if (o->count <= 0) {
        return;
    }
    if (o->index == newIndex || newIndex == 0) {
        return;
    }

    o->field70 = 0;
    o->index = newIndex;
    o->field78 = data_02114e50;
    o->field7c = *(int*)(*(char**)(o->table + o->index * 8 + 4) + o->field70 * 0xc + 4);
}
