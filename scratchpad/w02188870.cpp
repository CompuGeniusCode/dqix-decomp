#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Struct_0205bb84;
ARM int ComputeScaledSum0205bb84(struct Struct_0205bb84* s);

struct Container0205a3d0;
ARM void SetEntryByte14ByKey0205a42c(struct Container0205a3d0* c, int key, int val);
ARM void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);

struct Elem0205a3d0;
ARM struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);

ARM unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

struct Container0205a330;
ARM void IterateEntries0205a330(struct Container0205a330* c, int arg);

extern "C" void func_0205ae8c(int obj);

struct FlagElem02188870 {
    char pad[0x15];
    unsigned char flags15;
};

struct HalfElem02188870 {
    char pad[4];
    short h4;
    short h6;
};

struct Actor02188870 {
    char pad0[0x730];
    int f0x730;
    char pad1[0x738 - 0x734];
    struct Container0205a3d0* f0x738;
    char pad2[0x750 - 0x73c];
    char base750[1];
    char pad3[0xb18 - 0x751];
    int f0xb18;
    char pad4[0xb29 - 0xb1c];
    unsigned char f0xb29;
};

// USA: func_02188870
ARM void ApplyBattleScaling_02188870(struct Actor02188870* obj) {
    if (obj->f0x730 == 0) return;
    if (!(obj->f0xb18 & 0x8)) return;
    if (!(obj->f0xb18 & 0x80000)) return;

    struct BattleStruct* battle = GetBattleStruct();
    int scaled = ComputeScaledSum0205bb84((struct Struct_0205bb84*)&obj->base750);
    unsigned char b29 = obj->f0xb29;
    short computedVal = (short)(((scaled - b29) << 4) + 7);

    SetEntryByte14ByKey0205a42c(obj->f0x738, 0, 0x3f);
    SetEntryFlag2ByKey0205a370(obj->f0x738, 0);

    struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(obj->f0x738, 0);
    if (e != NULL) {
        ((struct FlagElem02188870*)e)->flags15 |= 8;
    }

    unsigned int scaleCount = GetBattleScaleCount(battle);
    IterateEntries0205a330((struct Container0205a330*)obj->f0x738, scaleCount);

    struct Elem0205a3d0* e2 = FindEntryByHalfword0205a3d0(obj->f0x738, 0);
    if (e2 != NULL) {
        ((struct HalfElem02188870*)e2)->h4 = 4;
        ((struct HalfElem02188870*)e2)->h6 = computedVal;
    }

    func_0205ae8c(obj->f0x730);
}
