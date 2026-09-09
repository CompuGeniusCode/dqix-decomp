#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Obj02094ab0 {
    unsigned char pad0[0x14];
    int handles[8];
    int field34;
    int field38;
    unsigned char pad1[0x54 - 0x3c];
    unsigned char field54;
    unsigned char field55;
    unsigned char field56;
    unsigned char field57;
    unsigned char pad2[0x61 - 0x58];
    unsigned char field61;
    unsigned char field62;
};

// Drops every background load this object still has outstanding: the eight words at +0x14 are
// BackgroundLoader task ids with -1 meaning empty, so each live one goes to RemoveTask and is
// blanked. It also restores +0x34/+0x38, +0x54..+0x57 and +0x61/+0x62 to the values func_02094a24
// gives them, but not that function's other fields, so this is not a full re-initialisation. What
// the owning object is has not been worked out; ov017 and battle-phase code call it when tearing
// a scene down.
extern "C" ARM void CancelBackgroundLoadTasks(struct Obj02094ab0* obj) {
    int a = (int)BackgroundLoader::GetInstance();
    unsigned char i;
    for (i = 0; i < 8; i++) {
        if (obj->handles[i] >= 0) {
            ((BackgroundLoader*)(a))->RemoveTask((int)(obj->handles[i]));
            obj->handles[i] = -1;
        }
    }
    obj->field34 = obj->field38 = -1;
    obj->field56 = 1;
    obj->field54 = obj->field55 = obj->field61 = obj->field62 = obj->field57 = 0;
}
