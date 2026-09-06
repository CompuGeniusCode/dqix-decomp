#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_020704fc(void*);
struct EffectParam020708c8;
void SetScaledEffectParam020708c8(struct EffectParam020708c8*, unsigned int);

// USA: func_ov001_0215b384
ARM int InitEffectFromField0_0215b384(void* self) {
    int v = func_ov017_021d60f4(self);
    void* handle = func_020704fc((void*)v);
    if (handle != NULL) {
        SetScaledEffectParam020708c8((struct EffectParam020708c8*)handle, v);
    }
    return 1;
}
