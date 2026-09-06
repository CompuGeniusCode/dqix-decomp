#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int CheckFlag0x14Bit0x10Set(unsigned char* obj);

// USA: func_ov024_021d8db4
ARM int ComputeCombatantScaledValue_021d8db4(int a, int b, int id, int c, int d, int fallback) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantFromList(battleStruct, id);
    if (combatant == NULL) {
        return fallback;
    }
    if (CheckFlag0x14Bit0x10Set((unsigned char*)combatant->currentStats) ||
        (*(int*)((char*)combatant->currentStats + 0x14) & 0x20) != 0) {
        return (int)(fallback * 2.0f);
    }
    return fallback;
}
