#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int CheckBitsInField0x63dc(void* obj, int mask);

// USA: func_ov004_021688bc
ARM int CheckBattleStructBitsMask2_021688bc_021688bc(void) {
    CheckBitsInField0x63dc(GetBattleStruct(), 2);
    return 0;
}
