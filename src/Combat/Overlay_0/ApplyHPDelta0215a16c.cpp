#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_0215a16c
ARM short ApplyHPDelta0215a16c(void* unused, int id, int delta, short* outApplied) {
    struct CombatantStruct* c = GetCombatantFromList(GetBattleStruct(), id);
    if (c == 0) {
        return 0;
    }
    int cur = c->currentStats->primaryStats.currHP;
    *outApplied = (short)delta;
    int newVal = cur + delta;
    if (newVal > c->currentStats->primaryStats.maxHP) {
        int applied = c->currentStats->primaryStats.maxHP - c->currentStats->primaryStats.currHP;
        *outApplied = (short)applied;
        newVal = c->currentStats->primaryStats.maxHP;
    }
    c->currentStats->primaryStats.currHP = (unsigned short)newVal;
    return (short)newVal;
}
