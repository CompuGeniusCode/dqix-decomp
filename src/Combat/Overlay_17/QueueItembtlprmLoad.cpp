#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);

struct Combatant;
extern "C" unsigned char func_ov017_021b354c(Combatant* combatant);
extern "C" int GetCombatantRecord(unsigned char* combatant);

extern int strDataPrmItembtlprmNat;
extern short data_ov017_021d6b56;
extern short data_ov017_021d6b54;

struct ItemLoadRequest {
    unsigned char unknown0[8];
    short id;
    unsigned char unknowna[4];
    int taskId;
};

// Re-requests data/prm/itembtlprm.nat for the combatant when what it carries no longer matches what was
// set up: the dirty byte at +0x56e of the sub-object at +0x150, cleared here, or a mismatch in one of
// eight slots, the pair table at data_ov017_021d6b54 indexing the 0x20-byte array at +0x194 and the
// 0x2c-byte array at +0x2f4 and comparing the shorts at +0x18 and +0x28. Both arrays are filled from
// that same file -- +0x194 by func_ov017_021b3560, +0x2f4 by func_ov017_021b3780 over the eight slots
// at data_ov017_021d6b20 -- so with eight equipment slots the pair is presumably a set and its copy.
// A negative first half of a pair-table entry means that slot is skipped. The object passed in
// carries the combatant it is for in the short at +8, which GetCombatantWithFlag0x100 looks up, and
// takes back the BackgroundLoader task the queue call returns in its word at +0x10. Which of the two
// arrays is the set and which the copy is not established, so they are spelled only entries and
// records here.
extern "C" ARM int QueueItembtlprmLoad(struct ItemLoadRequest* request) {
    struct BattleStruct* bs = GetBattleStruct();
    int loader = (int)BackgroundLoader::GetInstance();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, request->id);
    if (!combatant) {
        return 0;
    }
    if (!GetCombatantRecord((unsigned char*)combatant)) {
        return 0;
    }

    if (func_ov017_021b354c((Combatant*)combatant)) {
        char* sub = *(char**)((char*)combatant + 0x150);
        if (sub) {
            *(unsigned char*)(sub + 0x56e) = 0;
        }
        request->taskId = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)&strDataPrmItembtlprmNat), (SafeAllocator*)(0));
        return 1;
    }

    char* subBase = *(char**)((char*)combatant + 0x150);
    char* paramEntries = subBase + 0x194;
    char* paramRecords = subBase + 0x2f4;
    unsigned char slot;
    for (slot = 0; slot < 8; slot = (slot + 1) & 0xff) {
        short entryIndex = *(short*)((char*)&data_ov017_021d6b54 + slot * 4);
        if (entryIndex < 0) {
            continue;
        }
        short recordIndex = *(short*)((char*)&data_ov017_021d6b56 + slot * 4);
        short entryValue = *(short*)(paramEntries + entryIndex * 0x20 + 0x18);
        short recordValue = *(short*)(paramRecords + recordIndex * 0x2c + 0x28);
        if (entryValue == recordValue) {
            continue;
        }
        request->taskId = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)&strDataPrmItembtlprmNat), (SafeAllocator*)(0));
        return 1;
    }
    return 1;
}
