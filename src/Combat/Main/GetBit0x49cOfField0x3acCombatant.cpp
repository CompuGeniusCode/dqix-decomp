#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);

struct Sub0x150_02068580 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_02068580
ARM int GetBit0x49cOfField0x3acCombatant(struct BattleStruct* battleStruct) {
    struct CombatantStruct* combatant = GetCombatantAtField0x3ac(battleStruct);
    if (combatant != 0) {
        struct Sub0x150_02068580* sub = *(struct Sub0x150_02068580**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
