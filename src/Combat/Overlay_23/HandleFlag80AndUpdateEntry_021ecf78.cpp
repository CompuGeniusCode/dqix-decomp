#include <globaldefs.h>

struct BattleStruct;
BattleStruct* GetBattleStruct();
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

struct Container0205a3d0;
struct Container0205a330;
void SetEntryByte14ByKey0205a42c(struct Container0205a3d0* c, int key, int val);
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);
void IterateEntries0205a330(struct Container0205a330* c, int arg);
extern "C" void func_0205ae8c(void* p);

struct Elem0205a3d0_021ecf78 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    char pad8[0x15 - 8];
    unsigned char flags15;
};
struct Elem0205a3d0_021ecf78* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);

struct Obj021ecf78 {
    char pad0[0x424];
    void* f424;
    char pad428[0x42c - 0x428];
    struct Container0205a3d0* container;
    char pad430[0x438 - 0x430];
    unsigned short f438;
    char pad43a[0x448 - 0x43a];
    short f448;
};

// USA: func_ov023_021ecf78  (semantic: HandleFlag80AndUpdateEntry_021ecf78)
extern "C" ARM void func_ov023_021ecf78(struct Obj021ecf78* obj) {
    if ((obj->f438 & 0x80) == 0) {
        return;
    }

    struct BattleStruct* battleStruct = GetBattleStruct();
    SetEntryByte14ByKey0205a42c(obj->container, 0, 0x40);
    SetEntryFlag2ByKey0205a370(obj->container, 0);

    struct Elem0205a3d0_021ecf78* entry = FindEntryByHalfword0205a3d0(obj->container, 0);
    if (entry != NULL) {
        entry->flags15 |= 8;
    }

    unsigned int scaleCount = GetBattleScaleCount(battleStruct);
    IterateEntries0205a330((struct Container0205a330*)obj->container, scaleCount);

    short pos = obj->f448;
    struct Elem0205a3d0_021ecf78* entry2 = FindEntryByHalfword0205a3d0(obj->container, 0);
    if (entry2 != NULL) {
        entry2->field4 = pos;
        entry2->field6 = 0x24;
    }

    func_0205ae8c(obj->f424);
}
