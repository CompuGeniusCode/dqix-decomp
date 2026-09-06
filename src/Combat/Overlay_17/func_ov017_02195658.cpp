#include <globaldefs.h>

struct BattleStruct* GetBattleStruct(void);
struct SearchStruct;
extern "C" struct SearchStruct* func_0202ae18(void);
int TestFlagBitAt0xe(struct SearchStruct* obj, int value);
struct CombatantStruct* GetCombatantWithFlag0x200(struct BattleStruct* battleStruct, int combatantId);
extern "C" void func_ov017_021905b8(void* self, int idx, int flag);

// USA: func_ov017_02195658  (semantic: FindAndPrepareCombatantSlot_02195658)
extern "C" ARM int func_ov017_02195658(unsigned char* self) {
    struct BattleStruct* battle = GetBattleStruct();
    struct SearchStruct* search = func_0202ae18();
    for (int i = 1; i < 4; i++) {
        int flagA = 0;
        int flagB = 1;
        struct CombatantStruct* c = GetCombatantWithFlag0x200(battle, i);
        unsigned char* ptr = *(unsigned char**)(self + 0x4000 + 0x41c);
        if (ptr[0] == 1 && ptr[2] == i) {
            if (c != NULL) {
                flagA = flagB;
                flagB = 0;
            }
        }
        if (TestFlagBitAt0xe(search, i) != 0) flagA = 1;
        if (flagA != 0) {
            func_ov017_021905b8(self, i, flagB);
            if (flagB != 0) {
                unsigned char* ptr2 = *(unsigned char**)(self + 0x4000 + 0x41c);
                if (ptr2[0] != 0 && ptr2[2] == i) {
                    ptr2[0] = 0;
                    ptr2[1] = 0;
                    unsigned char* other = *(unsigned char**)(self + 0x3000 + 0xb30);
                    if (other[3] != 0) other[8] = 1;
                }
            }
            return i;
        }
    }
    return -1;
}
