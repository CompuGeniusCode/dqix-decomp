#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Foo02057930;
void ClearCombatantSlot(struct BattleStruct* battleStruct, int id);
void InitStruct02057930(Foo02057930* p);

// USA: func_02057978
ARM void ClearCombatantsAndInitStruct02057978(Foo02057930* p) {
    struct BattleStruct* bs = GetBattleStruct();
    int i;
    for (i = 0; i < 16; i++) {
        ClearCombatantSlot(bs, i + 0xd0);
    }
    InitStruct02057930(p);
}
