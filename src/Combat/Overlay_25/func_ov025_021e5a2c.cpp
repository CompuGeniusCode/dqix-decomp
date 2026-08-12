#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetActiveCombatWork(void);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
void CopyVec3(int* dst, int* src);

// USA: func_ov025_021e5a2c
extern "C" ARM int func_ov025_021e5a2c(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int f = GetField0x3b0Value(bs);
    if (f != 0) {
        CopyVec3((int*)(f + 4), (int*)((char*)obj + 8));
    }
    void* w = GetActiveCombatWork();
    if (w) {
        *(unsigned char*)((char*)w + 0x6000 + 0xfd5) = 1;
    }
    return 1;
}
