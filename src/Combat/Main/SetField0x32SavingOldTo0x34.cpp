#include <globaldefs.h>

struct SetField0208978c {
    unsigned char pad[0x32];
    short field32;
    short field34;
};

// USA: func_0208978c
ARM void SetField0x32SavingOldTo0x34(struct SetField0208978c* p, short value) {
    p->field34 = p->field32;
    p->field32 = value;
}
