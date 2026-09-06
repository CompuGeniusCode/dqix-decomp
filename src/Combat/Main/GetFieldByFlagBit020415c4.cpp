#include <globaldefs.h>

struct Obj020415c4 {
    char unk0[0x54];
    int field54;
    char unk58[0x54];
    unsigned short flags;
    char unkae[0x2];
    int fieldb0;
};

// USA: func_020415c4
ARM int GetFieldByFlagBit020415c4(struct Obj020415c4* obj) {
    if (obj->flags & 0x2) {
        return obj->fieldb0;
    }
    return obj->field54;
}
