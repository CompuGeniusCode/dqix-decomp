#include <globaldefs.h>

void ClearFlags0x14And0x58AndBytes(unsigned char* p);
void ClearFlag0x2AndBytes(unsigned char* p);
void ClearFlag0x4AndBytes(unsigned char* p);

struct Obj02087e6c {
    char pad0[0x14];
    int field14;
    char pad18[0x58 - 0x18];
    volatile int field58;
    char pad5c[0x75 - 0x5c];
    unsigned char byte75;
    char pad76[0x98 - 0x76];
    unsigned char byte98;
};

// USA: func_02087e6c
ARM int ClampAndUpdateField0x58(struct Obj02087e6c* obj, int delta) {
    int val = delta + ((obj->field58 << 8) >> 29);

    if (val > 2) {
        val = 2;
    }
    if (val < -2) {
        val = -2;
    }

    if (val == 0) {
        ClearFlags0x14And0x58AndBytes((unsigned char*)obj);
        return 0;
    }

    obj->field58 = (obj->field58 & ~0xe00000) | (((unsigned int)(val << 29)) >> 8);
    obj->byte75 = 5;
    obj->byte98 = 0;
    obj->field14 |= 0x20000;
    ClearFlag0x2AndBytes((unsigned char*)obj);
    ClearFlag0x4AndBytes((unsigned char*)obj);
    return (obj->field58 << 8) >> 29;
}
