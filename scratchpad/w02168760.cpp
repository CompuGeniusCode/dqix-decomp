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
void EnqueueEventTag58_021cf594(unsigned short a, unsigned char b, unsigned char c);

// USA: func_ov004_02168760
ARM int SendEventTag58ForFlaggedCombatants_02168760(void) {
    void* battle = GetBattleStruct();
    ResetAndEnableFieldFlag((struct FieldFlagBlock*)battle);

    char buf[0x70];
    VectorizedMemset(buf, 0, 0x70);

    signed char one = 1;
    signed char negOne = one - 2;
    signed char zero = 0;

    *(short*)(buf + 0x0) = 0x1130;
    *(int*)(buf + 0x14) = (int)0xffffa334;
    *(int*)(buf + 0x18) = 0x1000;
    *(short*)(buf + 0x1c) = 0x323d;
    buf[0x8] = one;
    buf[0x9] = one;
    buf[0xb] = negOne;
    *(int*)(buf + 0x20) = negOne;
    *(int*)(buf + 0x24) = negOne;
    *(int*)(buf + 0x28) = negOne;
    *(int*)(buf + 0x2c) = negOne;
    *(short*)(buf + 0x1e) = negOne;
    buf[0xc] = zero;
    *(short*)(buf + 0x6c) = negOne;
    buf[0x2] = one;
    buf[0x4] = zero;
    buf[0x5] = zero;
    *(int*)(buf + 0x10) = zero;
    buf[0x7] = one;

    CallFunc0200fbb4AtField0x3f8_0200fba4(battle, buf);
    unsigned short target = *(unsigned short*)func_02012fe4();

    for (signed char i = one; i < 4; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x800((struct BattleStruct*)battle, i);
        if (!c) continue;
        if (GetCombatantWithFlag0x1000((struct BattleStruct*)battle, i)) continue;
        if (target != GetU16At0x6((struct U16Field0x6_020375f8*)c)) continue;
        EnqueueEventTag58_021cf594(0x1130, i, one);
    }
    return 0;
}
