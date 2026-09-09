#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

// Takes a working copy of the 0xb0-byte record block at game state +0x7540. Every caller follows the
// same read, bump, write-back shape against func_020ac494: func_020ac4f8 folds elapsed
// time into the clocks at +0 and +0x68, and into +4 and +0x6c as well when committing, each capped
// at 9999 hours 59 minutes 59 seconds; the others increment saturating counters elsewhere in the
// block. Around sixty functions in ov023 (sub_menu) each read one field out of the block and hand it
// to func_ov017_021d6134, so that is the display side, though the screen's in-game name is unknown.
extern "C" ARM int CopyOutPlayRecords(void* dst) {
    char* base;
    memset(dst, 0, 0xb0);
    base = (char*)GetBattleStruct() + 0x104 + 0x7400;
    memcpy(dst, base + 0x3c, 0xb0);
    return 1;
}
