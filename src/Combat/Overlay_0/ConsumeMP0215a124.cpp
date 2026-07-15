#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_0215a124
ARM int ConsumeMP0215a124(void* unused, int id, int amount) {
    struct CombatantStruct* c = GetCombatantFromList(GetBattleStruct(), id);
    if (c == 0) {
        return 0;
    }
    int newMP;
    struct ModifiableCombatStats* stats = c->currentStats;
    newMP = stats->primaryStats.currMP - amount;
    if (newMP <= 0) {
        newMP = 0;
    }
    stats->primaryStats.currMP = (unsigned short)newMP;
    return (short)newMP;
}
