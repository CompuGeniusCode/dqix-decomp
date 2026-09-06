#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov000_02161318(void* obj, int idx);

int GetFieldAt0x150(unsigned char* obj);
int HasAnyFlags_021719f8_021719f8(int* obj);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov000_021756b8  (semantic: NotifyEligibleCombatants_021756b8)
extern "C" ARM void func_ov000_021756b8(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    unsigned char* p2a04 = (unsigned char*)GetPtrField0x2a04(bs);
    unsigned char count = p2a04[0xf7c];
    unsigned char i;
    for (i = 0; i < count; i++) {
        signed char combatantId = *((signed char*)p2a04 + i + 0xf00 + 0x78);
        struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, combatantId);
        if (c == 0) {
            continue;
        }
        int ptrVal = GetFieldAt0x150((unsigned char*)c);
        int val = *(int*)(ptrVal + 0x94c);
        signed char statusByte = (signed char)val;
        if (statusByte == 5) {
            continue;
        }
        void* e = func_ov000_02161318(obj, combatantId);
        if (e == 0) {
            continue;
        }
        if (HasAnyFlags_021719f8_021719f8((int*)e) == 0) {
            signed char off = *((signed char*)e + 0x18);
            unsigned char* p = (unsigned char*)e + off;
            p[0x10] = 0xd;
        }
    }
}
