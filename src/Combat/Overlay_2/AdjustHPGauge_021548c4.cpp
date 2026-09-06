#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct GaugeState0130 {
    char pad[4];
    unsigned short cur;
};

// USA: func_ov002_021548c4  (semantic: AdjustHPGauge_021548c4)
extern "C" ARM short func_ov002_021548c4(void* obj, int combatantId, int delta, unsigned char* status) {
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(GetBattleStruct(), combatantId);
    if (combatant == 0) {
        return 0;
    }

    unsigned short maxHP = combatant->baseStats->primaryStats.maxHP;
    unsigned short cur = (*(struct GaugeState0130**)((char*)combatant + 0x130))->cur;
    int sum = cur + delta;
    int amount;

    if (sum >= maxHP) {
        amount = maxHP - cur;
        if (amount == 0) {
            *status = 0;
        } else {
            *status = 3;
        }
    } else {
        *status = 3;
        amount = sum - cur;
    }

    (*(struct GaugeState0130**)((char*)combatant + 0x130))->cur = cur + amount;
    return (short)amount;
}
