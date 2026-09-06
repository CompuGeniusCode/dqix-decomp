#include <globaldefs.h>
int GetField0x3b4Value(struct BattleStruct*);
#include "Combat/Main/BattleList.h"

extern "C" void func_02054028(void* obj, int n);

// USA: func_0205416c
ARM void ConsumeCountdown0205416c(void* obj) {
    unsigned int n = (unsigned int)GetField0x3b4Value((struct BattleStruct*)(GetBattleStruct()));
    unsigned short v = *(unsigned short*)((char*)obj + 0x1c0);
    if (v >= n) {
        *(unsigned short*)((char*)obj + 0x1c0) = v - n;
        return;
    }
    func_02054028(obj, 0);
}
