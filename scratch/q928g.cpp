#include <globaldefs.h>
#include <Combat/Main/BattleList.h>
extern "C" void func_02036e34(void* obj, void* member, int arg3);
extern unsigned char data_ov000_021838df;
ARM void test(char* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    signed char* pA = (signed char*)(obj + 0x773c);
    unsigned char* pB = (unsigned char*)(obj + 0x7740);
    int i = 0;
    do {
        signed char s = pA[i];
        if (s >= 0) {
            int b = pB[i] - 1;
            if (b > 0) { pB[i] = (unsigned char)b; }
            else {
                pA[i] = -1;
                struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, s);
                if (c != NULL) func_02036e34(c, &data_ov000_021838df, 1);
            }
        }
        i++;
    } while (i < 4);
}
