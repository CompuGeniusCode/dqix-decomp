#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021eadfc
ARM int IsCombatantFlag2Mask512_021eadfc(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x18) & 0x200) != 0;
}
