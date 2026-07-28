#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetData02104304Field4();
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
int GetFieldAt0x150(unsigned char* obj);
struct Obj02083508;
void InitIndexedElements02083508(struct Obj02083508* o);
int InitAndDispatch020deef4(int a0, int a1, int a2, short* a3, short a4);

extern "C" {
    int func_0202fdd0(int a, int b);
    void func_02072afc(int id, int* arr, short* arr2);
    void func_020301c8(int a, int b);
    void func_02052d7c(void* combatant, int arg1, int arg2);
}

struct Pair8_021b3560 { int a; int b; };
extern struct Pair8_021b3560 data_ov017_021d6b78[];
extern struct Pair8_021b3560 data_ov017_021d6b74[];

struct Obj021b3560 {
    unsigned char pad0[8];
    short field8;
    char pad1[6];
    int field10;
};

// USA: func_ov017_021b3560  (semantic: DispatchAndSyncTable_021b3560)
extern "C" ARM int func_ov017_021b3560(struct Obj021b3560* self) {
    struct BattleStruct* bs = GetBattleStruct();
    int listPtr = GetData02104304Field4();
    if (!func_0202fdd0(listPtr, self->field10)) {
        return 0;
    }

    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, self->field8);
    if (!combatant) {
        return 0;
    }

    void* obj150 = (void*)GetFieldAt0x150((unsigned char*)combatant);
    if (!obj150) {
        return 0;
    }

    int bufA[11];
    short bufB[12];
    func_02072afc(self->field8, bufA, bufB);

    int out1, out2;
    GetListEntryValues0202fec8((struct List0202fec8*)listPtr, self->field10, &out1, &out2);
    InitIndexedElements02083508((struct Obj02083508*)obj150);
    InitAndDispatch020deef4((int)((char*)obj150 + 0x194), out1, out2, bufB, 11);
    func_020301c8(listPtr, self->field10);
    self->field10 = -1;

    int idx;
    for (idx = 0; data_ov017_021d6b74[idx].a >= 0; idx++) {
        int entry = data_ov017_021d6b78[idx].a;
        short valA = *(short*)((char*)obj150 + entry * 0x20 + 0x1ac);
        if (valA != bufB[entry]) {
            func_02052d7c(combatant, data_ov017_021d6b74[idx].a, -1);
        }
    }
    return 1;
}
