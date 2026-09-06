#include <globaldefs.h>

extern "C" int func_0206ef94(void* ctx, int value, int zero);

struct Fixup0206ef48 {
    int f0;
    int f4;
    unsigned char pad[0xc];
    int f14;
};

// USA: func_0206ef48
ARM int RelocateThreeFields(void* ctx, struct Fixup0206ef48* obj) {
    obj->f0 = func_0206ef94(ctx, obj->f0, 0);
    obj->f14 = func_0206ef94(ctx, obj->f14, 0);
    obj->f4 = func_0206ef94(ctx, obj->f4, 0);
    return 1;
}
