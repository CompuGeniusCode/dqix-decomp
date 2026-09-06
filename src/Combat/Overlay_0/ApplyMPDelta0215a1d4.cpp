#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_0215a1d4
ARM short ApplyMPDelta0215a1d4(void* unused, int id, int delta, short* outApplied) {
    struct CombatantStruct* c = GetCombatantFromList(GetBattleStruct(), id);
    if (c == 0) {
        return 0;
    }
    int cur = c->currentStats->primaryStats.currMP;
    *outApplied = (short)delta;
    int newVal = cur + delta;
    if (newVal > c->currentStats->primaryStats.maxMP) {
        int applied = c->currentStats->primaryStats.maxMP - c->currentStats->primaryStats.currMP;
        *outApplied = (short)applied;
        newVal = c->currentStats->primaryStats.maxMP;
    }
    c->currentStats->primaryStats.currMP = (unsigned short)newVal;
    return (short)newVal;
}
