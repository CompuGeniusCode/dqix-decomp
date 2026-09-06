#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

extern "C" int func_ov000_02155f9c(struct Random* rand, int combatantId, int zero);
extern "C" float func_ov000_02156270(struct Random* rand, int combatantId);
int IsFlag0x18Bit0x400Set(struct CombatantStruct* combatant);

struct FlagsObj02156f98 {
    char pad[0x10];
    unsigned int field10;
};

// USA: func_ov000_02156f98  (semantic: RollActionChance_02156f98)
extern "C" ARM int func_ov000_02156f98(struct Random* rand, int combatantId, struct FlagsObj02156f98* flagsObj) {
    GetBattleStruct();
    if (!(flagsObj->field10 & 0x20)) {
        return 0;
    }
    if (func_ov000_02155f9c(rand, combatantId, 0) != 0) {
        return 0;
    }
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantFromList(bs, combatantId);
    if (combatant == 0) {
        return 0;
    }
    if (IsFlag0x18Bit0x400Set(combatant)) {
        short val = *(short*)((char*)rand + 0x8e00 + 0x6e);
        return val < 0x32;
    }
    float chance = func_ov000_02156270(rand, combatantId);
    int roll = NextRandomMax(rand, 100);
    return roll < (int)chance;
}
