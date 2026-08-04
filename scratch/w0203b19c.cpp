#include <globaldefs.h>

void* GetGlobalContext020daf90(void);
int ProcessCombatantAnimRequest020db9cc(void* obj, int arg1, int arg2, int arg3);

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

// USA: func_0203b19c
extern "C" ARM void SetActorAnimTimer0203b19c(struct SelfB19C* self, int arg1, int arg2) {
    void* ctx;
    if (self->flag0x25 != 0) {
        return;
    }
    ctx = GetGlobalContext020daf90();
    if (!ProcessCombatantAnimRequest020db9cc(ctx, 1, arg1, arg2)) {
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
