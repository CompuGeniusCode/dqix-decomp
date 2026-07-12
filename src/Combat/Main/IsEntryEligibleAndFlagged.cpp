#include <globaldefs.h>

struct Inner0201bc94 {
    unsigned char lowBits : 4;
    unsigned char flag4 : 1;
    unsigned char highBits : 3;
};

struct Struct0201bc94 {
    unsigned short field0;
    unsigned short field2;
    unsigned short field4;
    unsigned short field6;
    Inner0201bc94* field8;
};

// USA: func_0201bc94
ARM int IsEntryEligibleAndFlagged(Struct0201bc94* obj) {
    int result = 1;
    if (obj->field0 == 0x2710) {
        result = 0;
    }
    else if (obj->field0 == 0x2774) {
        result = 0;
    }
    else if (obj->field4 == 0x170c) {
        result = 0;
    }
    else if (obj->field4 == 0x1901) {
        result = 0;
    }
    else {
        Inner0201bc94* inner = (Inner0201bc94*)((char*)obj->field8 + 0xc);
        if (!inner->flag4)
            result = 0;
    }
    return result;
}
