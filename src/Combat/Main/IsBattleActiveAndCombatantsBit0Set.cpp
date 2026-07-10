#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Obj02086b98;
extern "C" struct Obj02086b98* func_02010828(struct BattleStruct*);
int AreListedCombatantsBit0Set(struct Obj02086b98*);

// USA: func_0209c140
ARM int IsBattleActiveAndCombatantsBit0Set() {
    struct BattleStruct* bs = GetBattleStruct();
    if (bs != NULL) {
        struct Obj02086b98* o = func_02010828(bs);
        if (o != NULL) {
            if (AreListedCombatantsBit0Set(o) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
