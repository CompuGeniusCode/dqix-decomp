#include <globaldefs.h>

extern "C" int func_0202fdd0(int a, int b);
int GetData02104304Field4();

struct Struct0216fd38 {
    volatile int field0;
    unsigned char pad[0xa0 - 0x4];
    unsigned char flagA0;
};

// USA: func_ov000_0216fd38
ARM int CheckOrSetFlagA0_0216fd38(struct Struct0216fd38* obj) {
    if (obj->flagA0) return 1;
    if (obj->field0 < 0) return 0;
    if (func_0202fdd0(GetData02104304Field4(), obj->field0) == 0) {
        return 0;
    }
    obj->flagA0 = 1;
    return 1;
}
