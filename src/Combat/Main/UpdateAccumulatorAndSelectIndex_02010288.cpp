#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern float data_020f33b4[];

// USA: func_02010288  (semantic: UpdateAccumulatorAndSelectIndex_02010288)
extern "C" ARM void func_02010288(struct BattleStruct* battleStruct, float value) {
    if (value >= *(float*)((char*)battleStruct + 0x3d0)) {
        float scaled = (float)(int)(value / *(float*)((char*)battleStruct + 0x3d0));
        value = value - scaled * *(float*)((char*)battleStruct + 0x3d0);
    }
    *(float*)((char*)battleStruct + 0x3cc) = value;
    if (value >= *(float*)((char*)battleStruct + 0x3d0)) {
        *(float*)((char*)battleStruct + 0x3cc) = *(float*)((char*)battleStruct + 0x3cc) - *(float*)((char*)battleStruct + 0x3d0);
    }
    if (*(float*)((char*)battleStruct + 0x3cc) >= data_020f33b4[2]) {
        *(int*)((char*)battleStruct + 0x3dc) = 3;
        return;
    }
    if (*(float*)((char*)battleStruct + 0x3cc) >= data_020f33b4[3]) {
        *(int*)((char*)battleStruct + 0x3dc) = 2;
        return;
    }
    if (*(float*)((char*)battleStruct + 0x3cc) >= data_020f33b4[4]) {
        *(int*)((char*)battleStruct + 0x3dc) = 1;
    } else {
        *(int*)((char*)battleStruct + 0x3dc) = 0;
    }
}
