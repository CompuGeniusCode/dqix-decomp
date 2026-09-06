#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);

struct GaugeState02154944 {
    char pad[6];
    unsigned short currMP;
};

// USA: func_ov002_02154944
extern "C" ARM short func_ov002_02154944(void* obj, int combatantId, int delta, unsigned char* status) {
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(GetBattleStruct(), combatantId);
    if (combatant == 0) {
        return 0;
    }

    GetFieldAt0x150((unsigned char*)combatant);

    unsigned short maxMP = combatant->baseStats->primaryStats.maxMP;
    unsigned short currMP = (*(struct GaugeState02154944**)((char*)combatant + 0x130))->currMP;
    int sum = currMP + delta;
    int amount;

    if (sum >= maxMP) {
        amount = maxMP - currMP;
        if (amount == 0) {
            *status = 0;
        } else {
            *status = 3;
        }
    } else {
        *status = 3;
        amount = sum - currMP;
    }

    (*(struct GaugeState02154944**)((char*)combatant + 0x130))->currMP = currMP + amount;
    return (short)amount;
}
