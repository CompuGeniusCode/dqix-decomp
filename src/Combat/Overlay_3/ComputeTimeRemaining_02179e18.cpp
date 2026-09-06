#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

struct Obj02179e18 {
    char pad0[0x1a];
    unsigned short f1a;
};

// USA: func_ov003_02179e18
ARM unsigned int ComputeTimeRemaining_02179e18(struct Obj02179e18* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    void* p = GetPtrField0x2a04(bs);
    unsigned int v = *(unsigned int*)((char*)p + 0xf6c);
    return _u32_div_f(0x98967f - v, obj->f1a);
}
