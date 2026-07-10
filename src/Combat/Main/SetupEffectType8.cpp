#include <globaldefs.h>

struct Action020cca80 {
    char pad0[0x8];
    int field8;
    int fieldC;
    int field10;
};

extern "C" int func_020cbf58(void*, int);

// USA: func_020cca80
ARM int SetupEffectType8(struct Action020cca80* obj) {
    if (func_020cbf58(obj, 8) == 0) {
        return 0;
    }
    obj->field8 = 0;
    obj->field10 = 0xe;
    obj->fieldC &= ~0x30;
    return 1;
}
