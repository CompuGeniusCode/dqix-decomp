#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void CollectValidCombatants02010890(struct BattleStruct* bs, int* outList, int* outCount);

// USA: func_0202c3e0
ARM void StoreValidCombatantCount0202c3e0(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int list[4];
    int count;
    CollectValidCombatants02010890(bs, list, &count);
    *((unsigned char*)obj + 0x1027) = (unsigned char)count;
}
