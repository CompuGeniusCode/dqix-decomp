#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetGlobalField0x1c020421a0();
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(int a, int b);

// USA: func_020d844c
ARM void RunBattleScaleStepAndFinalize(void) {
    struct BattleStruct* b = GetBattleStruct();
    int x = GetGlobalField0x1c020421a0();
    unsigned int y = GetBattleScaleCount(b);
    Forward0204359c((void*)x, y);
    func_020439b0(x, 0);
}
