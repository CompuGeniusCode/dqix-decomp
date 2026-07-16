#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetWord0x0(int* obj);
int GetGlobalField0x1c020421a0(void);
void SetBothCounters(void* obj, int value, int frames);

struct Obj02186280 { char pad[0xb11]; unsigned char b11; };

// USA: func_ov008_02186280
ARM void ResetCounterIfIdle_02186280(struct Obj02186280* obj) {
    int v = GetWord0x0((int*)GetBattleStruct());
    GetGlobalField0x1c020421a0();
    if (obj->b11 == 0) {
        SetBothCounters((void*)v, 0, 0xf);
        obj->b11++;
    }
}
