#include <globaldefs.h>

struct Entry_203dce4 {
    int flags;
};

struct EntryList_203dce4 {
    char pad[0xc];
    struct Entry_203dce4* entries[0x20];
};

// Fetches one of the 32 actor slots hanging off the list at +0xc, refusing the slot when bit
// 0x8000 of the flag word at its offset 0 is set. The slots hold scene actors: func_ov001_0215f740
// tears one down by destroying the Object3D at +0x18 or releasing the "%s.spr" sprite it names,
// and func_0203e524 sweeps all 32 comparing world positions. There is one such
// list, reached through GetFieldObjectRegistry. What 0x8000 marks is not established; callers that
// already hold a slot re-test the same bit, which seems to mean the slot is on its way out.
extern "C" ARM struct Entry_203dce4* GetActorSlot(struct EntryList_203dce4* list, int id) {
    struct Entry_203dce4* entry;
    if ((unsigned int)id >= 0x20) {
        return 0;
    }
    entry = list->entries[id];
    if (entry != 0 && (entry->flags & 0x8000)) {
        entry = 0;
    }
    return entry;
}
