#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02159964
ARM int IsCombatantFlag0x2000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x2000) != 0;
}
