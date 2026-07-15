#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021eda60
ARM int IsCombatantFlagMask512_021eda60(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x200) != 0;
}
