#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02159994
ARM int IsCombatantFlag0x8000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x8000) != 0;
}
