#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int CheckBitsInField0x63dc(void* obj, int mask);
void ClearFieldKeepBit0x10(void* obj);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);

// USA: func_ov004_02168884  (semantic: ClearFlagAndSetArrayBit_02168884)
extern "C" ARM int func_ov004_02168884(void) {
    struct BattleStruct* battle = GetBattleStruct();
    CheckBitsInField0x63dc(battle, 1);
    ClearFieldKeepBit0x10(battle);
    void* p = func_0205ec34();
    SetOrClearBitInArray(p, (unsigned char*)p + 0x8c, 3, 0);
    return 0;
}
