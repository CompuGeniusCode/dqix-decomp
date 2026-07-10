#include <globaldefs.h>

struct DeltaSelectorState020ccc10;
int AddDeltaBySelectorClampAt0x2c(struct DeltaSelectorState020ccc10* s, int value, int mode);
int SetupEffectWithFlag0_020ccc00(void* obj, int a1, int a2);

struct Obj020c00c8 {
    char pad0[0xa4];
    int field_a4;
};

// USA: func_020c00c8
ARM int AdjustDeltaThenSetupEffect020c00c8(struct Obj020c00c8* obj, int b, int c, int d) {
    AddDeltaBySelectorClampAt0x2c((struct DeltaSelectorState020ccc10*)((char*)obj + 0x5c), obj->field_a4 + d, 0);
    return SetupEffectWithFlag0_020ccc00((char*)obj + 0x5c, b, c);
}
