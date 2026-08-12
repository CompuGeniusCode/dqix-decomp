#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int CheckBitsInField0x63dc(void* obj, int mask);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
int GetFieldAt0x0(int* obj);
extern "C" int func_ov017_021d6134(void* arg0, int level);

// USA: func_ov011_02187f7c
extern "C" ARM int func_ov011_02187f7c(void* arg0) {
    int level = 0;
    BattleStruct* battle = GetBattleStruct();
    if (CheckBitsInField0x63dc(battle, 1)) {
        if (CheckBitsInField0x63dc(battle, 2)) level = 1;
        if (CheckBitsInField0x63dc(battle, 4)) level = 2;
        if (CheckBitsInField0x63dc(battle, 8)) level = 3;
        int* obj = (int*)func_0202ae18();
        if (CheckField0NonZero(obj)) {
            if (GetFieldAt0x0(obj) == 6) level = 4;
        }
    }
    func_ov017_021d6134(arg0, level);
    return 1;
}
