#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int* func_0202ae18(void);
extern "C" int func_ov017_0218b5b0(void);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c508(void* obj);
extern "C" int func_ov017_02195760(int obj);
void SetByte2IfGlobalFlagSet(unsigned char* p);
extern "C" void func_ov017_021ced48(int a, unsigned char b);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct SearchStruct;
int TestFlagBitAt0xe(struct SearchStruct* obj, int value);

// USA: func_020e35a0
ARM void UpdateGlobalAndCombatantFlagBytes(unsigned char* p) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int obj2 = func_ov017_0218b5b0();
    int* searchObj = func_0202ae18();
    if (!CheckField0NonZero(searchObj)) return;

    if (func_0202c508(searchObj)) {
        int i;
        if (func_ov017_02195760(obj2)) {
            for (i = 0; i < 4; i++) {
                if (p[0] & (1 << i)) {
                    if (i == 0) {
                        SetByte2IfGlobalFlagSet(p);
                    } else {
                        func_ov017_021ced48(1, (unsigned char)i);
                    }
                }
            }
            p[1] |= p[0];
            p[0] = 0;
        }
        for (i = 1; i < 4; i++) {
            if (!GetCombatantUnchecked(battleStruct, i) || TestFlagBitAt0xe((struct SearchStruct*)searchObj, i)) {
                p[0] &= ~(1 << i);
                p[1] &= ~(1 << i);
            }
        }
    } else {
        if (TestFlagBitAt0xe((struct SearchStruct*)searchObj, 0)) {
            p[2] = 1;
        }
    }
}
