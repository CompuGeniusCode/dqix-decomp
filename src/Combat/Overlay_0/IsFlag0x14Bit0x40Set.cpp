#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02156b20
ARM int IsFlag0x14Bit0x40Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)(combatant->currentStats->unk1 + 0) & 0x40) != 0;
}
