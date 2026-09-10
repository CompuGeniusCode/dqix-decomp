#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Returns the camera the world is currently drawn through. Object3D's world pass copies the Matrix3x3
// at +0x144 of this object into the render config for anything flagged OBJECT3D_FLAG_19, which is how
// billboards end up facing the viewer. func_0202ea4c and ov001 read +0x4 and +0x10 as an eye/target
// pair, deriving heading (wrapped at 0x6488, 2*pi in fix32), height difference and distance; the
// LightingManager reads +0x120 and +0x12c instead. ov001 swaps cameras push/pop style, stashing the
// old one before installing a fresh 0x268-byte one through SetActiveCamera and restoring it afterwards.
extern "C" ARM int GetActiveCamera(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3b0);
}
