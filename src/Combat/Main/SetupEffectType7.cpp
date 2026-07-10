#include <globaldefs.h>

struct Action020cc980 {
    char pad0[0x8];
    int field8;
    int fieldC;
    char pad10[0x30 - 0x10];
    int field30;
    int field34;
    int field38;
};

extern "C" int func_020cbf58(void*, int);

#pragma optimize_for_size off
// USA: func_020cc980
ARM int SetupEffectType7(struct Action020cc980* obj, int a1, int a2, int a3, int a4) {
    obj->field8 = a1;
    obj->field38 = a4;
    obj->field30 = a2;
    obj->field34 = a3;
    if (func_020cbf58(obj, 7) == 0) {
        return 0;
    }
    obj->fieldC = (obj->fieldC | 0x10) & ~0x20;
    return 1;
}
