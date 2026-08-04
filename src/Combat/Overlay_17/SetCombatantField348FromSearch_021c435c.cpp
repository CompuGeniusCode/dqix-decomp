#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4*);
int TestBitAt0x34(unsigned char*, unsigned int);
extern "C" void* func_ov017_021b8478(void* obj);

struct U16Field0x6_020375f0;
void SetU16At0x6(struct U16Field0x6_020375f0*, unsigned short);

struct Src021c435c {
    unsigned char pad0[4];
    unsigned char field4;
    unsigned char loNibble : 4;
    unsigned char hiNibble : 4;
    unsigned short field6;
    unsigned short field8;
};

// USA: func_ov017_021c435c  (semantic: SetCombatantField348FromSearch_021c435c)
extern "C" ARM void func_ov017_021c435c(int unused0, struct Src021c435c* src, struct BattleStruct* battleStruct, unsigned char* obj, struct SearchStruct0202c1a4* search) {
    if (src->field4 & 1) {
        if (GetSearchStructCurrentArrEntry(search) != src->hiNibble) return;
    }
    unsigned int idx = src->loNibble;
    if (idx == GetSearchStructCurrentArrEntry(search)) return;
    struct CombatantStruct* c = GetCombatantWithFlag0x100(battleStruct, idx);
    if (!c) return;
    unsigned short val = src->field6;
    if (src->field4 & 2) val = src->field8;
    unsigned char* node = *(unsigned char**)(obj + 0x3000 + 0x718);
    void* p = func_ov017_021b8478(node);
    if (node[2] != 0) {
        if (TestBitAt0x34((unsigned char*)p, src->loNibble)) {
            *(unsigned int*)((char*)c + 0x15c) = val;
            return;
        }
    }
    SetU16At0x6((struct U16Field0x6_020375f0*)c, val);
}
