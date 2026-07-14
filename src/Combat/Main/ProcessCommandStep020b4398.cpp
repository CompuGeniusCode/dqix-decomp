#include <globaldefs.h>

struct Obj020b4398;

struct Mgr020b4398 {
    unsigned char pad0[0x18];
    void* field18;
    int (*field1c)(void* target, void* ctx, int code);
    unsigned char pad1[0x4c - 0x20];
    unsigned int bitwords[1];
};

struct Obj020b4398 {
    unsigned char* field0;
    Mgr020b4398* field4;
    unsigned int field8;
    unsigned char pad0[0x14 - 0xc];
    void (*field14)(Obj020b4398*);
    unsigned char pad1[0x8e - 0x18];
    unsigned char field8e;
    unsigned char pad2[0xac - 0x8f];
    unsigned char fieldac;
    unsigned char pad3[0xb8 - 0xad];
    void* fieldb8;
};

// USA: func_020b4398
ARM void ProcessCommandStep(Obj020b4398* obj) {
    if (obj->field8 & 0x200) goto tail;

    {
        unsigned char opcode = obj->field0[1];
        unsigned char mode;
        int flag40;

        obj->fieldac = opcode;
        obj->field8 |= 0x4;
        obj->fieldb8 = (unsigned char*)obj + 0x184;

        if (obj->field14 != NULL) mode = obj->field8e; else mode = 0;

        if (mode == 1) {
            obj->field8 &= ~0x40;
            obj->field14(obj);
            if (obj->field14 != NULL) mode = obj->field8e; else mode = 0;
            flag40 = obj->field8 & 0x40;
        } else {
            flag40 = 0;
        }

        if (flag40 == 0) {
            Mgr020b4398* mgr = obj->field4;
            void* bits = mgr->field18;
            if (bits != NULL) {
                if (mgr->bitwords[(unsigned int)opcode >> 5] & (1u << (opcode & 0x1f))) {
                    if (mgr->field1c(obj->fieldb8, bits, opcode) != 0) goto skipC;
                }
            }
            *(int*)obj->fieldb8 = obj->field0[2] & 1;
        }

skipC:
        if (mode == 2) {
            obj->field8 &= ~0x40;
            obj->field14(obj);
            if (obj->field14 != NULL) mode = obj->field8e; else mode = 0;
            flag40 = obj->field8 & 0x40;
        } else {
            flag40 = 0;
        }

        if (flag40 == 0) {
            if (*(int*)obj->fieldb8 != 0) obj->field8 |= 0x1; else obj->field8 &= ~0x1;
        }

        if (mode == 3) {
            obj->field8 &= ~0x40;
            obj->field14(obj);
        }
    }

tail:
    obj->field0 = obj->field0 + 3;
}
