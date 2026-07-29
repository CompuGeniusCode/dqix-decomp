#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov017_021d6134(void*, int);
int GetField0x3acValue(struct BattleStruct* battleStruct);

// USA: func_ov001_0215ef20  (semantic: SetFieldFromField3ac_0215ef20)
extern "C" ARM int func_ov001_0215ef20(void* self) {
    struct BattleStruct* battle = GetBattleStruct();
    int v = GetField0x3acValue(battle);
    func_ov017_021d6134(self, v);
    return 1;
}
