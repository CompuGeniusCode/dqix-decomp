#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct LoadTaskOwner {
    unsigned char unknown0[0x14];
    int handles[8];
    int unknown34;
    int unknown38;
    unsigned char unknown3c[0x54 - 0x3c];
    unsigned char unknown54;
    unsigned char unknown55;
    unsigned char unknown56;
    unsigned char unknown57;
    unsigned char unknown58[0x61 - 0x58];
    unsigned char unknown61;
    unsigned char unknown62;
};

// Drops every background load this object still has outstanding: the eight words at +0x14 are
// BackgroundLoader task ids with -1 meaning empty, so each live one goes to RemoveTask and is
// blanked. It also restores +0x34/+0x38, +0x54..+0x57 and +0x61/+0x62 to the values func_02094a24
// gives them -- +0x56 to 1 and the rest to 0 or -1 -- but not that function's other fields, among
// them +0x3c and +0x40, which it sets to -1 alongside +0x34 and +0x38, so this is not the full
// re-initialisation. Nothing seen hands +0x34 or +0x38 to the loader, so whether they are task ids
// too is not established despite the shared sentinel. What the owning object is has not been worked
// out; ov017 and battle-phase code call it when tearing the scene down.
extern "C" ARM void CancelBackgroundLoadTasks(struct LoadTaskOwner* owner) {
    int loader = (int)BackgroundLoader::GetInstance();
    unsigned char slot;
    for (slot = 0; slot < 8; slot++) {
        if (owner->handles[slot] >= 0) {
            ((BackgroundLoader*)(loader))->RemoveTask((int)(owner->handles[slot]));
            owner->handles[slot] = -1;
        }
    }
    owner->unknown34 = owner->unknown38 = -1;
    owner->unknown56 = 1;
    owner->unknown54 = owner->unknown55 = owner->unknown61 = owner->unknown62 = owner->unknown57 = 0;
}
