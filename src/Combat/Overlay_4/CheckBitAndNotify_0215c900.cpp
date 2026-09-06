#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0215c900
#pragma optimize_for_size off
ARM int CheckBitAndNotify_0215c900(void* obj) {
    char* p1 = (char*)GetBattleStruct() + 0x26c;
    char* p = p1 + 0x5d00;
    int flags = *(unsigned short*)(p + 0xc);
    flags = flags << 0x13;
    flags = (unsigned)flags >> 0x13;
    if (flags & 0x20) {
        func_ov011_021848a0(obj, 2);
    } else {
        func_ov011_021848a0(obj, 1);
    }
    return 0;
}
