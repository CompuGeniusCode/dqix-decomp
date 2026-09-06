#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021c9d2c(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

// USA: func_ov000_0217616c  (semantic: Dispatch_0217616c)
extern "C" ARM void func_ov000_0217616c(char* obj) {
    struct CombatantStruct* c = GetCombatantWithFlag0x100(GetBattleStruct(), *(int*)(obj + 0x4c));
    if (c == 0) {
        return;
    }
    func_ov017_021c9d2c(*(int*)(obj + 0x4c), *(short*)(obj + 0xc), *(short*)(obj + 0x8), *(short*)(obj + 0xe),
                         *(short*)(obj + 0xa), *(int*)(obj + 0x28), 0, 0, 0);
}
