#include <globaldefs.h>

struct BitField0203402c {
    char pad[0xc4];
    unsigned short field15 : 15;
    unsigned short bit15 : 1;
};

// USA: func_0203402c
ARM int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p) {
    return p->field15 != 0;
}
