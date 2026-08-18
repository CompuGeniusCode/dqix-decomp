#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_0218b5b0(void);
class PMFClass021d8d40;
extern "C" int _Z29DispatchHandlerTable_021d8d40P16PMFClass021d8d40t(PMFClass021d8d40* obj1, unsigned short arg2);
extern "C" int _Z24ReadByteAt17122_02156858v(void);
void UnlockAndSetBothCounters(unsigned char* obj, int value, int frames);
extern "C" int _Z28InitAndCheckField3c_02153994v(void);

// USA: func_ov001_02155d54  (semantic: HandleField160AndUnlockCounters_02155d54)
extern "C" ARM int func_ov001_02155d54(void* obj) {
    GetBattleStruct();
    void* b = func_ov017_0218b5b0();
    int f160 = *(int*)((char*)obj + 0x160);
    if (f160 != 0) {
        int r = _Z29DispatchHandlerTable_021d8d40P16PMFClass021d8d40t((PMFClass021d8d40*)f160, 2);
        *((unsigned char*)obj + 0x164) = (r != 0);
    }
    if (((int(*)(void*))_Z24ReadByteAt17122_02156858v)(obj) != 0) {
        UnlockAndSetBothCounters((unsigned char*)b, -16, 0x1e);
        *(int*)((char*)obj + 0x15c) = 1;
        return 0xe;
    }
    return (_Z28InitAndCheckField3c_02153994v() != 1) ? *(unsigned short*)((char*)obj + 0xa) : 0xf;
}
