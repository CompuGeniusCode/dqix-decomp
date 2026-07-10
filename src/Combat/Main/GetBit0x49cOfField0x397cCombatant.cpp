#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

struct Sub0x150_020685cc {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_020685cc
ARM int GetBit0x49cOfField0x397cCombatant(struct BattleStruct* battleStruct) {
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battleStruct);
    if (combatant != 0) {
        struct Sub0x150_020685cc* sub = *(struct Sub0x150_020685cc**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
