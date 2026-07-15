#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set(struct CombatantStruct* combatant);

// USA: func_ov000_02153cc0
ARM void MaybeUpdatePacked02153cc0(int unused, int newVal, int* ref) {
    short id = (short)(*(volatile int*)ref);
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantFromList(bs, id);
    if (c != NULL && IsFlag10088Set((struct S_10088*)c) == 0 && IsFlag0x18Bit0x2000Set(c) == 0) return;
    *ref = newVal;
}
