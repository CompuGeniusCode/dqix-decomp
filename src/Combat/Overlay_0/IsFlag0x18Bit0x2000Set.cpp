#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02153c0c
ARM int IsFlag0x18Bit0x2000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 4) & 0x2000) != 0;
}
