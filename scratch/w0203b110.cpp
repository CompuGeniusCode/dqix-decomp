#include <globaldefs.h>

void* GetGlobalContext020daf90(void);
int ProcessCombatantAnimRequest020db9cc(void* obj, int arg1, int arg2, int arg3);

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

// USA: func_0203b110
extern "C" ARM void func_0203b110(struct SelfB110* self, int arg1, int arg2) {
    void* ctx;
    if (self->flag0x24 != 0) {
        return;
    }
    ctx = GetGlobalContext020daf90();
    if (!ProcessCombatantAnimRequest020db9cc(ctx, 0, arg1, arg2)) {
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
