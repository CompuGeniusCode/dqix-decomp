#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void*);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
extern "C" void _ZN8Object3D11MakeVisibleEv(void*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);

// USA: func_ov001_021605d4  (semantic: SetOrClearFlag6cForPairSlots_021605d4)
extern "C" ARM int func_ov001_021605d4(void* self) {
    int id1 = func_ov017_021d60f4(self);
    int flag = func_ov017_021d60f4((char*)self + 0x8);
    struct BattleStruct* battle = GetBattleStruct();
    int base = id1 * 0xc;
    struct CombatantStruct* c1 = GetCombatantUnchecked(battle, base + 0x1c);
    if (c1 != NULL && *(short*)((char*)c1 + 2) >= 0) {
        if (flag != 0) {
            _ZN8Object3D11MakeVisibleEv(c1);
        } else {
            _ZN8Object3D10MakeHiddenEv(c1);
        }
    }
    struct CombatantStruct* c2 = GetCombatantUnchecked(battle, base + 0x1d);
    if (c2 != NULL && *(short*)((char*)c2 + 2) >= 0) {
        if (flag != 0) {
            _ZN8Object3D11MakeVisibleEv(c2);
        } else {
            _ZN8Object3D10MakeHiddenEv(c2);
        }
    }
    return 1;
}
