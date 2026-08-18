#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "System/Memory.h"

struct FieldFlagBlock;
void ResetAndEnableFieldFlag(struct FieldFlagBlock* block);
extern "C" void* CallFunc0200fbb4AtField0x3f8_0200fba4(void* obj, void* buf);
extern "C" void* func_02012fe4(void);

struct CombatantStruct;
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
void EnqueueEventTag58_021cf594(unsigned short a, int b, unsigned char c);

struct EventConfigBlock_02168760 {
    short f0;
    char f2, f3, f4, f5, f6, f7, f8, f9, fa, fb, fc;
    char pad_d[3];
    int f10, f14, f18;
    short f1c, f1e;
    int f20, f24, f28, f2c;
    char pad_30[0x3c];
    short f6c;
    char pad_6e[2];
};

// USA: func_ov004_02168760
ARM int SendEventTag58ForFlaggedCombatants_02168760(void) {
    struct BattleStruct* battle = GetBattleStruct();
    ResetAndEnableFieldFlag((struct FieldFlagBlock*)battle);

    EventConfigBlock_02168760 buf;
    VectorizedMemset(&buf, 0, 0x70);

    short c1130 = 0x1130;
    int ca334 = (int)0xffffa334;
    short c323d = 0x323d;
    signed char one = 1;
    signed char negOne = one - 2;
    signed char zero = 0;

    buf.f0 = c1130;
    buf.f14 = ca334;
    buf.f18 = 0x1000;
    buf.f1c = c323d;
    buf.f8 = one;
    buf.f9 = one;
    buf.fb = negOne;
    buf.f20 = negOne;
    buf.f24 = negOne;
    buf.f28 = negOne;
    buf.f2c = negOne;
    buf.f1e = negOne;
    buf.fc = zero;
    buf.f6c = negOne;
    buf.f2 = one;
    buf.f4 = zero;
    buf.f5 = zero;
    buf.f10 = zero;
    buf.f7 = one;

    CallFunc0200fbb4AtField0x3f8_0200fba4(battle, &buf);
    unsigned short target = *(unsigned short*)func_02012fe4();

    signed char i = one;
    signed char cArg = i;
    for (; i < 4; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x800(battle, i);
        if (!c) continue;
        if (GetCombatantWithFlag0x1000(battle, i)) continue;
        if (target != GetU16At0x6((struct U16Field0x6_020375f8*)c)) continue;
        EnqueueEventTag58_021cf594(0x1130, i, cArg);
    }
    return 0;
}
