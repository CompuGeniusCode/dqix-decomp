#include <globaldefs.h>

struct Action020ccabc {
    char pad0[0x10];
    int field10;
    char pad14[0x30 - 0x14];
    int field30;
    int field34;
    unsigned short field38;
    unsigned short field3a;
};

extern "C" int func_020cbf58(void*, int);

// USA: func_020ccabc
ARM int SetupEffectType5(struct Action020ccabc* obj, int a1, int a2) {
    if (obj->field10 != 5) {
        obj->field38 = 0;
        obj->field3a = 0;
    }
    obj->field30 = a1;
    obj->field34 = a2;
    return func_020cbf58(obj, 5);
}
