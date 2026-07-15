#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov023_021e8f28(int v);
extern "C" void func_ov017_021d6134(void* obj, int v);

struct Sub0x150_021e93e0 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_ov023_021e93e0
ARM int SetField8FromBit49c_021e93e0(void* obj) {
    GetBattleStruct();
    void* p = func_ov023_021e8f28(func_ov017_021d60f4(obj));
    if (p == NULL) {
        return 0;
    }
    struct Sub0x150_021e93e0* q = *(struct Sub0x150_021e93e0**)((char*)p + 0x150);
    func_ov017_021d6134((char*)obj + 8, q->bit0);
    return 1;
}
