#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
void SetFlagBit_0218d4b8(unsigned char* base, int bit);
void ClearFlagBit_0218d4d0(void* obj, int bit);
extern "C" void func_ov017_02191aac(void* a0, int mode, int idx, unsigned char mask);

struct S021d26a4 {
    unsigned char pad0[4];
    unsigned char field4;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
};

// USA: func_ov017_021d26a4
ARM void UpdateFieldAndFlag_021d26a4(int unused0, S021d26a4* s, struct BattleStruct* battleStruct, void* ctx) {
    int base = func_ov017_0218b5b0();
    struct CombatantStruct* c = GetCombatantWithFlag0x800(battleStruct, s->field4);
    if (!c) return;
    int p = GetFieldAt0x150((unsigned char*)c);
    if (!p) return;
    *(unsigned char*)((char*)p + 0x56c) = (s->bit0 != 0);
    if (*(unsigned char*)((char*)p + 0x56c)) {
        func_ov017_02191aac(ctx, 1, s->field4, 2);
    }
    if (s->bit1) {
        SetFlagBit_0218d4b8((unsigned char*)(long)base, s->field4);
    } else {
        ClearFlagBit_0218d4d0((void*)(long)base, s->field4);
    }
}
