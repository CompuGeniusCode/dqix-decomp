#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetWord0x0(int* obj);
void SetBothCounters(void* obj, int value, int frames);
int CheckField0x14Or0x20Positive(int* obj);
int IsAnimationActive0209ca2c(void* obj);
void SetField0x3b0Value(struct BattleStruct* battleStruct, int value);
extern int data_02109bf4;

struct Obj021e3f34 { char pad[0x138]; int field138; char pad2[0x4e4 - 0x138 - 4]; unsigned char field4e4; };

// USA: func_ov023_021e3f34  (semantic: RefreshCounterAndAdvanceState_021e3f34)
extern "C" ARM void func_ov023_021e3f34(struct Obj021e3f34* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int val = GetWord0x0((int*)bs);
    if (obj->field4e4 == 0) {
        SetBothCounters((void*)val, -16, 15);
        obj->field4e4++;
    }
    if (CheckField0x14Or0x20Positive((int*)val)) return;
    if (IsAnimationActive0209ca2c(&data_02109bf4)) return;
    SetField0x3b0Value(bs, obj->field138);
    obj->field4e4 = 0;
    *(signed char*)((char*)obj + 0x4e7) = *(signed char*)((char*)obj + 0x400 + 0xe6);
    *(signed char*)((char*)obj + 0x4e6) = -1;
}
