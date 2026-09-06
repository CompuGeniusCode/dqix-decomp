#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400(struct BattleStruct* battleStruct, int combatantId);

struct Struct02159d94 {
    char pad[0x10];
    unsigned int skip1 : 3;
    unsigned int val : 2;
    unsigned int skip2 : 27;
};

// USA: func_ov000_02159d94
ARM int GetCombatantField0x148Bits3To4(int unused, int id) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x400(bs, id);
    struct Struct02159d94* field148 = *(struct Struct02159d94**)((char*)combatant + 0x148);
    return field148->val;
}
