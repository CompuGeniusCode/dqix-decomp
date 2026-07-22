#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_0202ae18(void);
void SetFlagAndCleanup_02195618(unsigned char* obj);
int GetField0x3acValue(struct BattleStruct* battleStruct);
extern "C" void func_ov017_02195398(int a, int b);
struct SearchStruct;
void SetSearchFlagBit0202c660(struct SearchStruct* obj, int value);
extern "C" void func_ov017_02191234(int a);
extern "C" void func_ov017_021905b8(int a, int b, int c);
struct S021b1454;
void ClearBitAtIndex_021b1454(struct S021b1454* obj, int bit);

// USA: func_ov017_0219558c
ARM void UpdateSearchFlagOrCleanup_0219558c(unsigned char* obj, int value) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int base = func_ov017_0218b5b0();
    struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
    if (value == 0) {
        SetFlagAndCleanup_02195618(obj);
        return;
    }
    if (value == GetField0x3acValue(battleStruct)) return;
    func_ov017_02195398(base, value);
    SetSearchFlagBit0202c660(search, value);
    func_ov017_02191234(base);
    func_ov017_021905b8(base, value, 1);
    ClearBitAtIndex_021b1454(*(struct S021b1454**)(obj + 0x3000 + 0xb34), (unsigned char)value);
}
