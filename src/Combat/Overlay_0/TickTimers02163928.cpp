#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* member, int arg3);
extern char data_ov000_021838df[];

// USA: func_ov000_02163928  (semantic: TickTimers02163928)
extern "C" ARM void func_ov000_02163928(char* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    int i;
    for (i = 0; i < 4; i++) {
        signed char timerId = *(signed char*)(obj + 0x773c + i);
        if (timerId < 0) continue;
        int counter = *(unsigned char*)(obj + 0x7740 + i);
        counter--;
        if (counter <= 0) {
            *(signed char*)(obj + 0x773c + i) = -1;
            struct CombatantStruct* c = GetCombatantWithFlag0x100(battle, timerId);
            if (c != 0) {
                _ZN8Object3D24MaybeSetRegularAnimationEPKci(c, data_ov000_021838df, 1);
            }
        } else {
            *(unsigned char*)(obj + 0x7740 + i) = counter;
        }
    }
}
