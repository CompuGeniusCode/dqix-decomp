#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set(struct CombatantStruct* combatant);
int IsFlag0x14Bit0x8Set(struct CombatantStruct* combatant);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);
int IsFlag0x14Bit0x80000Set(struct CombatantStruct* combatant);
int IsFlag0x14Bit0x20Set(struct CombatantStruct* combatant);

// USA: func_ov000_02155f9c  (semantic: IsCombatantIneligible_02155f9c)
extern "C" ARM int func_ov000_02155f9c(void* unused, int combatantId, int checkSubFlag) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantFromList(bs, combatantId);
    if (c == 0) {
        return 1;
    }
    if (IsFlag10088Set((struct S_10088*)c) ||
        IsFlag0x18Bit0x2000Set(c) ||
        IsFlag0x14Bit0x8Set(c) ||
        CheckFlag0x14Bit0x10Set((unsigned char*)c->currentStats) ||
        IsFlag0x14Bit0x80000Set(c)) {
        return 1;
    }
    if (checkSubFlag != 0 && IsFlag0x14Bit0x20Set(c)) {
        return 1;
    }
    return 0;
}
