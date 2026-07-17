#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int TestBitAt0x34(unsigned char* obj, unsigned int index);
struct ArrayContainsByteStruct;
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_02083c48(void* p, int flag, int mode);

// USA: func_ov000_021674f4
ARM void ProcessFlagits021674f4_021674f4(unsigned char* obj, int skipArrayCheck) {
    struct BattleStruct* battle = GetBattleStruct();
    struct ArrayContainsByteStruct* base = (struct ArrayContainsByteStruct*)GetPtrField0x2a04(battle);
    unsigned char* bits = *(unsigned char**)((char*)*(void**)(obj + 0x29c) + 0x8000 + 0xe18);
    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34(bits, (unsigned char)i)) continue;
        if (skipArrayCheck == 0) {
            if (!ArrayContainsByte(base, i)) continue;
        }
        struct CombatantStruct* c = GetCombatantWithFlag0x800(battle, i);
        if (!c) continue;
        int val150 = GetFieldAt0x150((unsigned char*)c);
        int contains = ArrayContainsByte(base, i);
        func_02083c48((void*)val150, contains, 1);
    }
}
