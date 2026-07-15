#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3acValue(struct BattleStruct* battleStruct);
int GetSignedByte0x2d0(void* obj);
struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov000_0215fd24
ARM int IsIdOrEffectMatchTarget0215fd24(int unused, int id) {
    struct BattleStruct* bs = GetBattleStruct();
    if (id == GetField0x3acValue(bs)) return 1;
    struct CombatantStruct* c = GetCombatantWithFlag0x1000(bs, id);
    if (c != NULL) {
        int signedByte = GetSignedByte0x2d0(c);
        if (signedByte == GetField0x3acValue(bs)) return 1;
    }
    return 0;
}
