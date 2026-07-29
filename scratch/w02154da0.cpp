#include <globaldefs.h>

struct EffectParam020708c8;

int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
extern "C" void* func_020704fc(void);
void SetScaledEffectParam020708c8(struct EffectParam020708c8* obj, unsigned int value);
extern "C" void* func_ov017_0218b5b0(void);
void SetBothCounters(void* obj, int value, int frames);

// USA: func_ov001_02154da0
ARM void ReinitCombatEffectsAndCounters_02154da0() {
    char* obj = (char*)GetGlobalField0x1c020421a0();
    ReinitController02043204(obj);
    func_02043124(obj);
    *(unsigned char*)(obj + 0x1000 + 0x9be) = 0;
    SetScaledEffectParam020708c8((struct EffectParam020708c8*)func_020704fc(), 0);
    SetBothCounters(func_ov017_0218b5b0(), -16, 0);
}
