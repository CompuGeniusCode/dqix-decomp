#include <globaldefs.h>

struct Entry_02028bd0;
extern struct Entry_02028bd0 data_020fdd44;

// Returns the base of the zone record table. data_020fdd44 runs to the next bss symbol at
// 0x020fe9a4, exactly four records of 0x318 bytes: FindZoneSlotById (0x02028bd0) walks the four
// matching the u16 at offset 0, and func_02028bac bounds-checks its index against 4 at the
// same stride. That id is a zone id -- func_02027cb0 and func_ov017_021cf4e8 both pass
// *GetZoneState() to the finder. Four fixed slots keyed by zone id, then; that all four are
// resident at once is an inference. ov017 gamemain is the heaviest caller, 25 of 41 sites.
extern "C" ARM struct Entry_02028bd0* GetZoneRecordTable(void) {
    return &data_020fdd44;
}
