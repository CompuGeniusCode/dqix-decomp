#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern int CheckBitsInField0x63dc(void* obj, int mask);
extern "C" void func_ov017_021d6134(void* param, int val);

// USA: func_ov001_021626a4
ARM int NotifyIfField63dcSet_021626a4(void* param) {
    struct BattleStruct* bs = GetBattleStruct();
    if (CheckBitsInField0x63dc(bs, 1)) {
        int val = CheckBitsInField0x63dc(bs, 1);
        func_ov017_021d6134(param, val);
    }
    return 1;
}
