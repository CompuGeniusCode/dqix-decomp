#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov017_021d6134(void*, int);
unsigned char GetField0x397cValue(struct BattleStruct* battleStruct);

// USA: func_ov001_02161d08  (semantic: SetFieldFromField397c_02161d08)
extern "C" ARM int func_ov001_02161d08(void* self) {
    struct BattleStruct* battle = GetBattleStruct();
    int v = GetField0x397cValue(battle);
    func_ov017_021d6134(self, v);
    return 1;
}
