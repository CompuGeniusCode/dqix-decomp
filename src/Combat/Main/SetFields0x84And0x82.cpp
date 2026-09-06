#include <globaldefs.h>

struct SetFieldsStruct {
    char unk0[0x80];
    unsigned short field80;
    unsigned short field82;
    int field84;
};

// USA: func_0201e878
extern "C" ARM void _ZN12ZoneFeatures21SetOpcode7bAllocationEPNS_13Opcode7bEntryEt(struct SetFieldsStruct* p, int value, short id) {
    p->field84 = value;
    p->field82 = id;
    p->field80 = 0;
}
