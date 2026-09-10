#include <globaldefs.h>
#include "System/Memory.h"

// Resets the pending zone change at the game state's +0x3f8, reached through GetZoneTransitionRequest;
// the game state constructor at 0x0200f41c inlines this same routine on that field. Every caller
// checked then fills in the destination: halfword 0 is the zone id (func_ov017_02199360 writes
// 0x2710 and 0x170c literally), +0x10 a Vector3i position copied off a combatant, +0x1c a facing
// angle. func_0208f944 reads halfword 0 as the destination and compares it with GetZoneState()'s
// current zone. The -1s written here are presumably "leave alone" values; which field is which is not
// worked out.
extern "C" ARM void InitZoneChangeRequest(char* obj) {
    VectorizedMemset(obj, 0, 0x70);
    obj[0x4] = 1;
    obj[0x8] = 1;
    obj[0x9] = 1;
    obj[0xb] = -1;
    *(int*)(obj + 0x20) = -1;
    *(int*)(obj + 0x24) = -1;
    *(int*)(obj + 0x28) = -1;
    *(int*)(obj + 0x2c) = -1;
    *(short*)(obj + 0x1e) = -1;
    obj[0xc] = 0;
    *(short*)(obj + 0x6c) = -1;
}
