#include <globaldefs.h>

struct Struct0202f700 {
    unsigned char field0;
    char pad1[0x17];
    unsigned char field18;
    char pad2[0x17];
    unsigned short field30;
    signed char lowNibble : 4;
    signed char highNibble : 4;
    unsigned char pad3;
    int field34;
    int field38;
    int field3c;
    unsigned short field40;
    unsigned short field42;
};

// USA: func_0202f700
ARM void ClearFieldsAndSetLowNibble(struct Struct0202f700* s) {
    s->field0 = 0;
    s->field18 = 0;
    s->field30 = 0;
    s->lowNibble = 0xf;
    s->field34 = 0;
    s->field38 = 0;
    s->field3c = 0;
    s->highNibble = 0;
    s->field40 = 0;
    s->field42 = 0;
}
