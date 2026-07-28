#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct S02163b90 { char pad[0x2a0]; unsigned char* bitsPtr; };

int TestBitAt0x34(unsigned char* obj, unsigned int index);
void ClearFlag0x1InField0x6c(unsigned char* obj);
void SetSubstructByte0x56(unsigned char* obj);
void SetFlag0x6cBit0(unsigned char* obj);
void ClearSubstructByte0x56(unsigned char* obj);

// USA: func_ov000_02163b90  (semantic: UpdateAllCombatantsFlagField6c_02163b90)
extern "C" ARM void func_ov000_02163b90(struct S02163b90* self, int clear) {
    struct BattleStruct* bs = GetBattleStruct();
    int id;
    for (id = 0; id <= 3; id++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, id);
        if (!c) continue;
        if (!TestBitAt0x34(self->bitsPtr, id & 0xff)) continue;
        if (clear) {
            ClearFlag0x1InField0x6c((unsigned char*)c);
            SetSubstructByte0x56((unsigned char*)c);
        } else {
            SetFlag0x6cBit0((unsigned char*)c);
            ClearSubstructByte0x56((unsigned char*)c);
        }
    }
}
