#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// The field at +0x3dc is the time zone: 0 night, 1 morning, 2 afternoon, 3 evening, after the map
// debug strings in data/bin/str_dbg_map_en.bin that index it. func_02010288 buckets the float clock
// at +0x3cc against thresholds 0/180/210/390 with the period 420 at +0x3d0 and a rate of one unit
// per second; func_02010364 and the game-state constructor also write the field directly.
// func_ov017_0218d0ec caches it in the lighting manager and raises event tag 147 on a change when
// IsHostOrSinglePlayer; func_02073ec4 takes type-1 entries only at phase 0 and type-0 otherwise.
extern "C" ARM int GetTimeOfDayPhase(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3dc);
}
