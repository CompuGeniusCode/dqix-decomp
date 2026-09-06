#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov023_021e8f28(int v);
extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021e9370
ARM int SetThreeFieldsFromSub150_021e9370(void* obj) {
    GetBattleStruct();
    void* p = func_ov023_021e8f28(func_ov017_021d60f4(obj));
    if (p == NULL) {
        return 0;
    }
    char* s = *(char**)((char*)p + 0x150);
    func_ov017_021d6134((char*)obj + 8, *(int*)(s + 0x950));

    s = *(char**)((char*)p + 0x150);
    int idx1 = *(int*)(s + 0x950);
    unsigned short v1 = *(unsigned short*)(s + idx1 * 2 + 0x100 + 0x6c);
    func_ov017_021d6134((char*)obj + 0x10, v1);

    s = *(char**)((char*)p + 0x150);
    int idx2 = *(int*)(s + 0x950);
    int v2 = *(int*)(s + idx2 * 4 + 0x138);
    func_ov017_021d6134((char*)obj + 0x18, v2);

    return 1;
}
