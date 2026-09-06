#include <globaldefs.h>
unsigned int GetBattleScaleCount(struct BattleStruct*);
#include "Combat/Main/BattleList.h"

extern "C" void func_02067b28(void* obj);

// USA: func_02067e58
ARM void RepeatStepClampedToField0x3c4(void* obj, int count) {
    struct BattleStruct* battleStruct;
    unsigned int minCount;
    if (count == 0) {
        return;
    }
    battleStruct = GetBattleStruct();
    minCount = GetBattleScaleCount((struct BattleStruct*)(battleStruct));
    if ((unsigned int)count < minCount) {
        count = minCount;
    }
    while (count > 0) {
        func_02067b28(obj);
        if (count != 0) {
            count--;
        }
    }
}
