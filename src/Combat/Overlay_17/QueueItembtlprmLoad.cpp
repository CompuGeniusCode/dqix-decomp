#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* func_0200ff1c(struct BattleStruct* battleStruct, int combatantId);

struct Obj150_021b354c;
extern "C" unsigned char func_ov017_021b354c(Obj150_021b354c* obj);
extern "C" int func_02053c6c(unsigned char* obj);

extern int strDataPrmItembtlprmNat;
extern short data_ov017_021d6b56;
extern short data_ov017_021d6b54;

struct Obj_021b3678 {
    unsigned char pad0[8];
    short id;
    unsigned char pad1[4];
    int result;
};

// Re-requests data/prm/itembtlprm.nat for the combatant when what it carries no longer matches what was
// set up: the dirty byte at +0x56e of the sub-object at +0x150, cleared here, or a mismatch in one of
// eight slots, the pair table at data_ov017_021d6b54 indexing the 0x20-byte array at +0x194 and the
// 0x2c-byte array at +0x2f4 and comparing the shorts at +0x18 and +0x28. Both arrays are filled from
// that same file -- +0x194 by func_ov017_021b3560, +0x2f4 by func_ov017_021b3780 over the eight slots
// at data_ov017_021d6b20 -- so with eight equipment slots the pair is presumably a set and its copy.
extern "C" ARM int QueueItembtlprmLoad(struct Obj_021b3678* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int field4 = (int)BackgroundLoader::GetInstance();
    struct CombatantStruct* combatant = func_0200ff1c(bs, obj->id);
    if (!combatant) {
        return 0;
    }
    if (!func_02053c6c((unsigned char*)combatant)) {
        return 0;
    }

    if (func_ov017_021b354c((Obj150_021b354c*)combatant)) {
        char* sub = *(char**)((char*)combatant + 0x150);
        if (sub) {
            *(unsigned char*)(sub + 0x56e) = 0;
        }
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadFile((const char*)((int)&strDataPrmItembtlprmNat), (SafeAllocator*)(0));
        return 1;
    }

    char* subBase = *(char**)((char*)combatant + 0x150);
    char* arrA = subBase + 0x194;
    char* arrB = subBase + 0x2f4;
    unsigned char i;
    for (i = 0; i < 8; i = (i + 1) & 0xff) {
        short t2 = *(short*)((char*)&data_ov017_021d6b54 + i * 4);
        if (t2 < 0) {
            continue;
        }
        short t1 = *(short*)((char*)&data_ov017_021d6b56 + i * 4);
        short valA = *(short*)(arrA + t2 * 0x20 + 0x18);
        short valB = *(short*)(arrB + t1 * 0x2c + 0x28);
        if (valA == valB) {
            continue;
        }
        obj->result = ((BackgroundLoader*)(field4))->QueueLoadFile((const char*)((int)&strDataPrmItembtlprmNat), (SafeAllocator*)(0));
        return 1;
    }
    return 1;
}
