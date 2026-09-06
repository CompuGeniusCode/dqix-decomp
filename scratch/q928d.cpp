#include <globaldefs.h>
#include <Combat/Main/BattleList.h>
extern "C" void func_02036e34(void* obj, void* member, int arg3);
extern unsigned char data_ov000_021838df;
struct ObjB { char pad[0x7740]; };
ARM void test(struct ObjB* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    unsigned char* pB = (unsigned char*)((char*)obj + 0x7740);
    signed char* pA = (signed char*)((char*)obj + 0x773c);
    for (int i = 0; i < 4; i++) {
        signed char s = pA[i];
        if (s < 0) continue;
        int b = pB[i] - 1;
        if (b > 0) {
            pB[i] = (unsigned char)b;
        } else {
            pA[i] = -1;
            struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, s);
            if (c != NULL) func_02036e34(c, &data_ov000_021838df, 1);
        }
    }
}
