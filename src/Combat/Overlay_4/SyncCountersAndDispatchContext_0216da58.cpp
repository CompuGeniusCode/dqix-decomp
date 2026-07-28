#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Overlay_17/Struct44C8.h"

unsigned char GetByte0x4(char* obj);
void SetBothCounters(void* obj, int value, int frames);
struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);
extern int data_02109bf4;
extern "C" int _s32_div_f(int a, int b);

// USA: func_ov004_0216da58  (semantic: SyncCountersAndDispatchContext_0216da58)
extern "C" ARM int func_ov004_0216da58() {
    BattleStruct* bs = GetBattleStruct();
    Struct_ov017_44C8* obj = func_ov017_0218b5b0();
    int frames = _s32_div_f(1000, 0x22);
    if (GetByte0x4((char*)bs) == 8) {
        SetBothCounters(obj, 0x10, frames);
    } else {
        SetBothCounters(obj, -16, frames);
    }
    if (GetByte0x4((char*)bs) != 2) {
        DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 0x10);
    }
    return 0;
}
