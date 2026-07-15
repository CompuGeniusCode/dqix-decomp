#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int CheckBitsInField0x63dc(void* obj, int mask);
extern "C" void func_ov017_0219c520(void);

// USA: func_ov001_021624a8
ARM int NotifyOverlay17IfFlag63dc_021624a8(void) {
    if (CheckBitsInField0x63dc(GetBattleStruct(), 1)) {
        func_ov017_0219c520();
    }
    return 1;
}
