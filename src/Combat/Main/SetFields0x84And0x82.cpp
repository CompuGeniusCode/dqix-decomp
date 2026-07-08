#include <globaldefs.h>

struct SetFieldsStruct {
    char unk0[0x80];
    unsigned short field80;
    unsigned short field82;
    int field84;
};

// USA: func_0201e878
ARM void SetFields0x84And0x82(struct SetFieldsStruct* p, int value, short id) {
    p->field84 = value;
    p->field82 = id;
    p->field80 = 0;
}
