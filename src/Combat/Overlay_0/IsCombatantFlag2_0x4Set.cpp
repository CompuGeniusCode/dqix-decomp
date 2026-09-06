#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02159904
ARM int IsCombatantFlag2_0x4Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x18) & 0x4) != 0;
}
