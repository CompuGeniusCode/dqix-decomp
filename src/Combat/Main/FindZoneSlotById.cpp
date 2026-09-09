#include <globaldefs.h>

struct Entry_02028bd0 {
    unsigned short id;
    char unk[0x316];
};

// Finds the resident-zone slot whose id matches, or null. The table is the four-entry array at
// data_020fdd44: func_02027cb0 looks it up with the zone id straight out of GetZoneState, and
// ov017's func_ov017_0219e384 feeds the same halfword to func_02028a54 first, which claims a
// free slot for a zone that is not resident yet.
// Each 0x318-byte slot owns two SafeAllocators and a 0x1320-byte block carved into twelve
// 0x198-byte combatants, registered in the BattleStruct list at index 0x70 + slot * 12.
// Four is a hard cap in both this search and func_02028bac, so a fifth zone cannot be resident.
extern "C" ARM struct Entry_02028bd0* FindZoneSlotById(struct Entry_02028bd0* base, int key) {
    int i;
    if (key < 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (key == base[i].id) {
            return &base[i];
        }
    }
    return 0;
}
