#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
extern "C" void func_02094b9c(void* self, void* data);

struct Field0x44_02094b5c { unsigned int v[3]; };

// USA: func_02094b5c
ARM void ForwardCombatantField0x44(void* self, int combatantId) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantUnchecked(bs, combatantId);
    struct Field0x44_02094b5c buf = *(struct Field0x44_02094b5c*)((char*)c + 0x44);
    func_02094b9c(self, &buf);
}
