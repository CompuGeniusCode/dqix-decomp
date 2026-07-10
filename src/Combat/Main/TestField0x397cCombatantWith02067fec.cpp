#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" int func_02067fec(int, void*, int);

// USA: func_02068a20
ARM int TestField0x397cCombatantWith02067fec(struct BattleStruct* battleStruct, int arg1, int arg2) {
    struct CombatantStruct* c = GetCombatantAtField0x397c(battleStruct);
    if (c != 0) {
        return func_02067fec(0, c->baseStats, arg2) == 0;
    }
    return 0;
}
