#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Milliseconds elapsed this frame, already scaled by the game speed factor. func_02010150 clamps
// the raw microsecond delta to 50000, divides by 1000 into +0x3b8, then multiplies by the factor
// at +0x3bc to produce +0x3b4; 0x1000 is 1.0 there, and ov000 runs a timed battle speed factor
// that expires back to 1.0. Both fields start at 0x21, one 30 fps frame, and +0x3c0 is the same
// delta divided by 17.0f as 20.12 fixed point. Every countdown and interpolation subtracts this,
// so despite living in BattleStruct it is not battle-specific -- Object3D and LightingManager use it.
extern "C" ARM int GetFrameDeltaMilliseconds(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3b4);
}
