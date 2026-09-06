#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Obj02049e88;
void ResetSubFlags02049e88(struct Obj02049e88* obj);
void ClearSubstructFlag0x4(unsigned char* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);

// USA: func_ov000_02167f10  (semantic: ResetSubFlagsForCombatants_02167f10)
extern "C" ARM void func_ov000_02167f10(unsigned char* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c;
    int i;
    for (i = 0; i < 4; i++) {
        if (TestBitAt0x34(*(unsigned char**)(obj + 0x2a0), i & 0xff)) {
            c = GetCombatantFromList(bs, i);
            if (c) {
                ResetSubFlags02049e88((struct Obj02049e88*)c);
                ClearSubstructFlag0x4((unsigned char*)c);
            }
        }
    }
    for (i = 0xc0; i < 0xc8; i++) {
        c = GetCombatantFromList(bs, i);
        if (c) {
            ResetSubFlags02049e88((struct Obj02049e88*)c);
            ClearSubstructFlag0x4((unsigned char*)c);
        }
    }
    obj[0x5951] &= ~0x3;
}
