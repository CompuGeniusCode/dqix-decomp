#include <globaldefs.h>

struct Entry34F8 {
    char pad0[3];
    unsigned char flags;
};

struct Node34F8 {
    char pad0;
    volatile unsigned char count;
    char pad2[4];
    unsigned short tableOff;
};

struct Sub34F8 {
    char pad0[2];
    unsigned short subOff;
};

struct Obj34F8 {
    char pad0[8];
    int obj8;
};

// Forces branches instead of if-conversion for this file's functions.
#pragma optimize_for_size off

// USA: func_020b34f8
ARM void ClearBit0OfEntries(struct Obj34F8* obj) {
    struct Sub34F8* sub;
    struct Node34F8* node;
    struct Entry34F8* e;
    unsigned char* base;
    unsigned int index;
    sub = (obj != 0 && obj->obj8 != 0) ? (struct Sub34F8*)((char*)obj + obj->obj8) : 0;
    node = (struct Node34F8*)((char*)sub + sub->subOff);
    index = 0;
    if (index < node->count) {
        do {
            if (node != 0 && index < node->count) {
                base = (unsigned char*)node + node->tableOff;
                e = (struct Entry34F8*)(base + 4 + (*(unsigned short*)base) * index);
            } else {
                e = 0;
            }
            if (e->flags & 1) {
                e->flags &= ~1;
            }
            index++;
        } while (index < node->count);
    }
}
