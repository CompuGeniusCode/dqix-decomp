#include <globaldefs.h>

extern "C" void* func_020daf90(void);
extern "C" int func_020db9cc(void* obj, int arg1, int arg2, int arg3);

struct SelfB110 {
    char pad0[0xc];
    float fC;
    int f10;
    int f14;
    char pad18[0x24 - 0x18];
    unsigned char flag0x24;
    unsigned char pad25;
    unsigned char flag0x26;
};

// Starts a master brightness fade on the main engine. The object is the one func_0203aee0 seeds
// from the two MASTER_BRIGHT registers: 0xc is the current level, 0x10 the target, 0x14 the
// milliseconds left, 0x24 a lock that suppresses the request, 0x26 the dirty flag func_0203b080
// consumes when it writes 0x400006c. func_0203af48 is the per-frame driver, stepping 0xc toward
// 0x10 by GetFrameDeltaMilliseconds; SetSubScreenBrightness is this routine 0xc higher for the sub engine.
// The level is the signed MASTER_BRIGHT factor, -16 black to +16 white; a zero duration snaps.
extern "C" ARM void StartMainEngineBrightnessFade(struct SelfB110* self, int arg1, int arg2) {
    void* ctx;
    if (self->flag0x24 != 0) {
        return;
    }
    ctx = func_020daf90();
    if (!func_020db9cc(ctx, 0, arg1, arg2)) {
        return;
    }
    if (arg2 == 0) {
        self->fC = (float)arg1;
        self->f10 = arg1;
        self->f14 = 0;
        self->flag0x26 = 1;
        return;
    }
    self->f10 = arg1;
    self->f14 = (int)(16.667f * (float)arg2);
}
