#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_02191fec(int a, int combatantId);

// USA: func_ov017_021c1264  (semantic: ApplyFlag800StatusToCombatants_021c1264)
extern "C" ARM void func_ov017_021c1264(void) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int a = func_ov017_0218b5b0();
    for (int i = 0; i < 4; i++) {
        if (GetCombatantWithFlag0x800(battleStruct, i) != NULL) {
            func_ov017_02191fec(a, i);
        }
    }
}
