#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
struct BattleStruct;
struct BattleStruct* GetBattleStruct(void);
void* GetPtrField0x2a04(struct BattleStruct* battleStruct);

// USA: func_ov002_02161920  (semantic: CheckAllElementFlagsSet_02161920)
extern "C" ARM int func_ov002_02161920(void) {
    if (CheckField0NonZero((int*)func_0202ae18())) {
        struct BattleStruct* bs = GetBattleStruct();
        unsigned char* base = (unsigned char*)GetPtrField0x2a04(bs);
        unsigned char i = 0;
        while (i < base[0xf7c]) {
            unsigned char* p = base + i;
            if (p[0xf78] == 0) {
                return 2;
            }
            i++;
        }
        return 1;
    }
    return 0;
}
