#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
extern "C" int DispatchAdjustmentIfType4_02157018(void* a, int key);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void*);
struct Struct021707d8_test { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_test data_ov004_021707d8;
extern "C" int func_ov017_021b213c(int, int);

// USA: func_ov004_0215b7f8
ARM int TestExact_0215b7f8(void* obj) {
    if (!DispatchAdjustmentIfType4_02157018(obj, 4)) return 0;
    char* battle = (char*)GetBattleStruct();
    char* p = battle + 0x26c;
    void* state = func_0202ae18();
    if (func_0202c508(state)) {
        int* aPtr = (int*)(p + 0x5d00);
        unsigned char* ptr = data_ov004_021707d8.ptr;
        int a = *aPtr;
        int b = *(int*)(ptr + 0x18);
        if (func_ov017_021b213c(a, b)) {
        }
    }
    return 0;
}
