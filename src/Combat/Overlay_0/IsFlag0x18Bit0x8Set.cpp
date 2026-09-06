#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02156c94
ARM int IsFlag0x18Bit0x8Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 4) & 0x8) != 0;
}
