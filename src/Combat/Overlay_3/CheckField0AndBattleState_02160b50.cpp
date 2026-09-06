// USA: func_ov003_02160b50
#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
int GetFieldAt0x0(int* obj);
int GetField0x3acValue(struct BattleStruct* battleStruct);

ARM int CheckField0AndBattleState_02160b50(void) {
    int result = 0;
    if (GetFieldAt0x0((int*)func_0202ae18())) {
        result = GetField0x3acValue(GetBattleStruct()) == 0 ? 1 : 2;
    }
    return result;
}
