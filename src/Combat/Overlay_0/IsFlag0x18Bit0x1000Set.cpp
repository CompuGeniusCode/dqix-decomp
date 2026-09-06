#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02155154
ARM int IsFlag0x18Bit0x1000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 4) & 0x1000) != 0;
}
