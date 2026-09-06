#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Obj02086aec;
short SumCombatantKeyMatches02086aec(struct Obj02086aec* obj, int key);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" void* func_ov023_021f6880(void* obj, int key);
int ScaleStatsIfType12_021f6f10(void* self);
extern "C" int func_ov023_021f9bc8(char* obj);
struct A2Struct02167b78 { short f0; short f2; };
extern "C" int func_ov004_02167b78(void* obj, struct A2Struct02167b78* entry);
extern "C" void func_ov011_021848a0(void* obj, int val);

extern char data_ov004_0216fff8;

// USA: func_ov004_02168318  (semantic: DispatchAreaAlertState_02168318)
extern "C" ARM int func_ov004_02168318(void* self) {
    short sum = SumCombatantKeyMatches02086aec((struct Obj02086aec*)GetPtrField0x2a04(GetBattleStruct()), 0x5617);
    void* node = func_ov023_021f6880(func_ov011_021849c8(self), 0xe);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 7) return 0;

    int idx = func_ov023_021f9bc8((char*)node);
    struct A2Struct02167b78* entry = 0;
    if (idx >= 0 && idx < 6) {
        entry = (struct A2Struct02167b78*)(&data_ov004_0216fff8 + idx * 4);
    }
    func_ov004_02167b78(self, entry);

    if (entry != 0 && sum >= entry->f0) {
        func_ov011_021848a0(self, 0x82);
    } else {
        func_ov011_021848a0(self, 0x84);
    }
    return 0;
}
