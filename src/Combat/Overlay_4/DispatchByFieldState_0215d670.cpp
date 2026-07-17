#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void);
struct SearchStruct;
int TestFlagBitAt0xe(struct SearchStruct* obj, int value);
extern "C" int func_ov004_0215c0c0(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0215d670
ARM int DispatchByFieldState_0215d670(void* obj) {
    char* p = (char*)GetBattleStruct() + 0x26c;
    void* s = func_0202ae18();
    unsigned short v = *(unsigned short*)(p + 0x5d00 + 0xc);
    int state = (unsigned int)(v << 16) >> 29;
    if (state == 1) {
        func_ov004_0215c0c0(obj);
        return 0;
    }
    if (state == 2) {
        func_ov011_021848a0(obj, 0x2367);
        return 0;
    }
    if (!TestFlagBitAt0xe((struct SearchStruct*)s, 0)) {
        return 1;
    }
    func_ov011_021848a0(obj, 0x2369);
    return 0;
}
