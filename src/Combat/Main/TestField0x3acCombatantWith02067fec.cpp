#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
extern "C" int func_02067fec(int, void*, int);

// USA: func_020689e4
ARM int TestField0x3acCombatantWith02067fec(struct BattleStruct* battleStruct, int arg1, int arg2) {
    struct CombatantStruct* c = GetCombatantAtField0x3ac(battleStruct);
    if (c != 0) {
        return func_02067fec(0, c->baseStats, arg2) == 0;
    }
    return 0;
}
