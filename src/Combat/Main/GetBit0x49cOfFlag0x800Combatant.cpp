#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct Sub0x150_02068558 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_02068558
ARM int GetBit0x49cOfFlag0x800Combatant(struct BattleStruct* battleStruct) {
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battleStruct, 0);
    if (combatant != 0) {
        struct Sub0x150_02068558* sub = *(struct Sub0x150_02068558**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
