#include <globaldefs.h>

extern "C" void* func_020daf90(void);
extern "C" int func_020db9cc(void* context, int engine, int level, int durationFrames);

struct ScreenBrightnessState {
    char unknown0[0x18];
    float subLevel;
    int subTargetLevel;
    int subFadeRemainingMs;
    char mainFadeLock[0x25 - 0x24];
    unsigned char subFadeLock;
    unsigned char mainDirty;
    unsigned char subDirty;
};

// Sets the sub screen's master brightness. func_0203b540 pushes the floats at +0xc and +0x18 of the
// gamemain context to MASTER_BRIGHT at 0x0400006c and 0x0400106c; this one owns the sub half, its
// twin at 0x0203b110 the main half, level -16 to 16, black through to white. A duration of zero
// writes the target at once and raises the sub dirty flag at +0x27, though func_0203b080 also gates
// its write on +0x28, which neither setter raises; otherwise the target parks at +0x1c and +0x20
// holds the fade time left. func_020db9cc can drop the request first. The duration arrives in
// frames and +0x20 is 16.667 milliseconds per frame of it, which func_0203af48 counts down by the
// millisecond frame delta -- not one unit per 60 Hz frame as this note used to say. The main
// half's lock and dirty flag are the bytes at +0x24 and +0x26 named here.
extern "C" ARM void SetSubScreenBrightness(struct ScreenBrightnessState* self, int level, int durationFrames) {
    void* globalContext;
    if (self->subFadeLock != 0) {
        return;
    }
    globalContext = func_020daf90();
    if (!func_020db9cc(globalContext, 1, level, durationFrames)) {
        return;
    }
    if (durationFrames == 0) {
        self->subLevel = (float)level;
        self->subTargetLevel = level;
        self->subFadeRemainingMs = 0;
        self->subDirty = 1;
        return;
    }
    self->subTargetLevel = level;
    self->subFadeRemainingMs = (int)(16.667f * (float)durationFrames);
}
