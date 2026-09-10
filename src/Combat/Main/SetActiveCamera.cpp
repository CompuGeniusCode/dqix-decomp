#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Installs the camera everything else renders through, at +0x3b0 of the global game state -- the
// field GetActiveCamera at 0x020100bc reads, and GetCameraIfFlag4 at 0x020100f8 reads when flag
// bit 4 is set. Event handlers in ov001 allocate a 0x268-byte camera, bind it to a combatant
// through Object3D bone tracking so it follows that character, and stash the camera it displaces
// in the slot at +0x5ca4+4, which func_ov001_0215f930 puts back; ov004 and ov014 restore from
// their own module slots. A caller that installs a camera owns restoring the previous one.
extern "C" ARM void SetActiveCamera(struct BattleStruct* battleStruct, int value) {
    *(int*)((char*)battleStruct + 0x3b0) = value;
}
