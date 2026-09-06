#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct Sub0x150_020685a4 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_020685a4
ARM int GetBit0x49cOfFlag0x800Combatant020685a4(struct BattleStruct* battleStruct) {
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battleStruct, 0);
    if (combatant != 0) {
        struct Sub0x150_020685a4* sub = *(struct Sub0x150_020685a4**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
