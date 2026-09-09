#include <globaldefs.h>

extern int data_02108e10;

// Returns the action-data tables. The static constructor clears four 0xc-byte table descriptors here;
// func_02079900 fills +0 and +0x18 from data/prm/actdt_a.gp2 (with actdt_a_<LG>.nat and
// actdamage_a.nat) and LoadBattleActdtTables fills +0xc and +0x24 from actdt_b.gp2 and actdamage_b.nat.
// Every caller hands the pointer straight to FindActdtEntryById, which searches the +0 and
// +0xc pair by the 12-bit id at +0x4 of a record; ov017 fetches this object and passes it to
// func_02079900 two instructions later.
extern "C" ARM void* GetActionDataTables(void) {
    return &data_02108e10;
}
