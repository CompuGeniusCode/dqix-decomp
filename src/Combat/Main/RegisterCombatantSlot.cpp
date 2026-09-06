#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct SlotBackRef_fd38 {
    char pad[4];
    unsigned short id;
};

// USA: func_0200fd38
ARM void RegisterCombatantSlot(struct BattleStruct* battleStruct, int id, struct CombatantStruct* combatant) {
    battleStruct->combatantList[id] = combatant;
    ((struct SlotBackRef_fd38*)combatant)->id = id;
}
