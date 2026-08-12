#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
int IsFieldNotPositive_021a4e70(unsigned char* base);
unsigned char GetByte0x26c(char* obj);

struct SrcFields_0219b33c {
    unsigned char field0;
    unsigned char field1;
    unsigned short field2;
    unsigned char field4;
    char pad5[3];
    int field8;
    int fieldc;
    short field10;
    short field12;
};

extern const unsigned char data_ov017_021d64a0[15];

struct Pair0219b33c { unsigned int v[2]; };
struct Buf15_0219b33c { unsigned char v[15]; };

// USA: func_ov017_0219b33c
extern "C" ARM void func_ov017_0219b33c(char* self, struct SrcFields_0219b33c* src) {
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(GetBattleStruct());

    if (!IsFieldNotPositive_021a4e70((unsigned char*)self)) return;

    if (combatant) {
        if (*(int*)((char*)combatant + 0x18c) & 1) return;
        if (GetByte0x26c((char*)combatant) != 0) return;
    }

    if (*(short*)(self + 0x36c4) < src->field10) return;
    if (*(int*)(self + 0x4080) != 0) return;

    *(unsigned char*)(self + 0x36b4) = src->field0;
    *(unsigned char*)(self + 0x36b5) = src->field1;
    *(unsigned short*)(self + 0x36b6) = src->field2;
    *(unsigned char*)(self + 0x36b8) = src->field4;
    *(struct Pair0219b33c*)(self + 0x36bc) = *(struct Pair0219b33c*)&src->field8;
    *(short*)(self + 0x36c4) = src->field10;
    *(short*)(self + 0x36c6) = src->field12;

    if (src->field1 != 0x12) return;

    struct Buf15_0219b33c bufWrap;
    unsigned char* buf = bufWrap.v;
    bufWrap = *(struct Buf15_0219b33c*)data_ov017_021d64a0;

    *(unsigned char*)(self + 0x36b5) = buf[src->field0];
}
