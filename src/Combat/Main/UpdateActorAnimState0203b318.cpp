#include <globaldefs.h>

void* GetGlobalContext020daf90(void);
int ProcessCombatantAnimRequest020db9cc(void* obj, int arg1, int arg2, int arg3);

struct SelfB318 {
    char pad0[0xc];
    float fC;
    int f10;
    int f14;
    char pad18[0x24 - 0x18];
    unsigned char flag0x24;
    unsigned char pad25;
    unsigned char flag0x26;
};

// USA: func_0203b318  (semantic: UpdateActorAnimState0203b318)
extern "C" ARM void func_0203b318(struct SelfB318* self, int arg1, unsigned int arg2) {
    void* ctx;
    unsigned int div;
    if (self->flag0x24 != 0) {
        return;
    }
    ctx = GetGlobalContext020daf90();
    div = (arg2 + arg2 * 2) / 100;
    if (!ProcessCombatantAnimRequest020db9cc(ctx, 0, arg1, div)) {
        return;
    }
    if (arg2 != 0) {
        self->f10 = arg1;
        self->f14 = arg2;
        return;
    }
    self->fC = (float)arg1;
    self->f10 = arg1;
    self->f14 = 0;
    self->flag0x26 = 1;
}
