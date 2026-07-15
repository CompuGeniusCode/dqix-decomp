#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02156b08
ARM int IsFlag0x18Bit0x40Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 4) & 0x40) != 0;
}
