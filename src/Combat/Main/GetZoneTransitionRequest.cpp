#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// The pending zone change sits at +0x3f8 of the game state root: destination zone id at +0, a
// Vector3i position at +0x10 and a facing angle at +0x1c, inside a 0x70 byte block that
// func_02070378 memsets and then seeds with defaults. Callers fill it from the current zone
// and the player's position and rotation, and byte 2 marks the request live -- the field code
// refuses to act while it is set. The ids match the u16 zone numbers Zone3D::SwitchZone takes.
// Whether it is only ever a warp request, or also a re-entry placement, is not established.
extern "C" ARM void* GetZoneTransitionRequest(struct BattleStruct* battleStruct) {
    return (char*)battleStruct + 0x3f8;
}
