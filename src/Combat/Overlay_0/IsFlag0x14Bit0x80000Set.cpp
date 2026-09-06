#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02156050
ARM int IsFlag0x14Bit0x80000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 0) & 0x80000) != 0;
}
