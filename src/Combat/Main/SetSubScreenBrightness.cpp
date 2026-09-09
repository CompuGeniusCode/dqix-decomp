#include <globaldefs.h>

extern "C" void* func_020daf90(void);
extern "C" int func_020db9cc(void* obj, int arg1, int arg2, int arg3);

struct SelfB19C {
    char pad0[0x18];
    float f18;
    int f1c;
    int f20;
    char pad24[0x25 - 0x24];
    unsigned char flag0x25;
    unsigned char pad26;
    unsigned char flag0x27;
};

// Sets the sub screen's master brightness. func_0203b540 pushes the floats at +0xc and +0x18 of the
// gamemain context to MASTER_BRIGHT at 0x0400006c and 0x0400106c; this one owns the sub half, its
// twin at 0x0203b110 the main half, level -16 to 16, black through to white. A duration of zero
// writes the target at once and raises the sub dirty flag at +0x27, though func_0203b080 also gates
// its write on +0x28, which neither setter raises; otherwise the target parks at +0x1c and +0x20
// counts one 60 Hz frame per unit. func_020db9cc can drop the request first.
extern "C" ARM void SetSubScreenBrightness(struct SelfB19C* self, int arg1, int arg2) {
    void* ctx;
    if (self->flag0x25 != 0) {
        return;
    }
    ctx = func_020daf90();
    if (!func_020db9cc(ctx, 1, arg1, arg2)) {
        return;
    }
    if (arg2 == 0) {
        self->f18 = (float)arg1;
        self->f1c = arg1;
        self->f20 = 0;
        self->flag0x27 = 1;
        return;
    }
    self->f1c = arg1;
    self->f20 = (int)(16.667f * (float)arg2);
}
