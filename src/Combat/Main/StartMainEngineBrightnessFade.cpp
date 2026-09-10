#include <globaldefs.h>

extern "C" void* func_020daf90(void);
extern "C" int func_020db9cc(void* context, int engine, int level, int durationFrames);

struct ScreenBrightnessState {
    char unknown0[0xc];
    float mainLevel;
    int mainTargetLevel;
    int mainFadeRemainingMs;
    char subFadeFields[0x24 - 0x18];
    unsigned char mainFadeLock;
    unsigned char subFadeLock;
    unsigned char mainDirty;
};

// Starts a master brightness fade on the main engine. The object is the one func_0203aee0 seeds
// from the two MASTER_BRIGHT registers: 0xc is the current level, 0x10 the target, 0x14 the
// milliseconds left, 0x24 a lock that suppresses the request, 0x26 the dirty flag func_0203b080
// consumes when it writes 0x400006c. func_0203af48 is the per-frame driver, stepping 0xc toward
// 0x10 by GetFrameDeltaMilliseconds; SetSubScreenBrightness is this routine 0xc higher for the sub
// engine, and the sub engine's own lock is the byte at 0x25 named here, its dirty flag the 0x27
// this declaration stops short of. The level is the signed MASTER_BRIGHT factor, -16 black to +16
// white; a zero duration snaps. The duration is counted in frames and stored as 16.667 milliseconds
// each, which is the unit the driver subtracts.
extern "C" ARM void StartMainEngineBrightnessFade(struct ScreenBrightnessState* self, int level, int durationFrames) {
    void* globalContext;
    if (self->mainFadeLock != 0) {
        return;
    }
    globalContext = func_020daf90();
    if (!func_020db9cc(globalContext, 0, level, durationFrames)) {
        return;
    }
    if (durationFrames == 0) {
        self->mainLevel = (float)level;
        self->mainTargetLevel = level;
        self->mainFadeRemainingMs = 0;
        self->mainDirty = 1;
        return;
    }
    self->mainTargetLevel = level;
    self->mainFadeRemainingMs = (int)(16.667f * (float)durationFrames);
}
