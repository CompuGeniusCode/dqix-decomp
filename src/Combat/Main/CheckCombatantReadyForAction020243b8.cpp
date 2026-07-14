#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Bits40_37464;
int GetField0x40Bits3To7(struct Bits40_37464* obj);
short GetShortAt0xa0(unsigned char* obj);
int CheckFlag0x6cBit0Clear(unsigned char* obj);

// USA: func_020243b8
ARM int CheckCombatantReadyForAction020243b8(void* unused, int combatantId) {
    if (combatantId < 0) {
        return 1;
    }
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(GetBattleStruct(), combatantId);
    if (combatant == NULL) {
        return 1;
    }
    if (GetField0x40Bits3To7((struct Bits40_37464*)combatant) == 0) {
        return 0;
    }
    if (GetShortAt0xa0((unsigned char*)combatant) == 0) {
        return 0;
    }
    return CheckFlag0x6cBit0Clear((unsigned char*)combatant) != 0;
}
