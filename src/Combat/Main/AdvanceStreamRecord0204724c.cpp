#include <globaldefs.h>

extern unsigned char data_02114e00;
extern unsigned int data_02114e50;

struct Descriptor0204724C {
    void* field0;
    unsigned char* field4;
};

struct Obj0204724C {
    unsigned char pad0[0xc];
    struct Descriptor0204724C* table;
    unsigned char pad10[0x70 - 0x10];
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned char pad80[0x84 - 0x80];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char restBits : 6;
};

// USA: func_0204724c
ARM void AdvanceStreamRecord0204724c(struct Obj0204724C* obj) {
    unsigned char* base;
    unsigned int off;

    if (!obj->bit0) return;
    if (!obj->bit1) return;

    if (data_02114e00 != 0) {
        obj->field78 = data_02114e50;
        return;
    }

    if (obj->field7c >= (data_02114e50 - obj->field78)) return;

    off = obj->field70 * 0xc;
    base = obj->table[obj->field74].field4;
    obj->field70 = *(unsigned int*)(base + off);
    base = base + off;
    obj->field78 = data_02114e50;
    obj->field7c = *(unsigned int*)(base + 4);
}
