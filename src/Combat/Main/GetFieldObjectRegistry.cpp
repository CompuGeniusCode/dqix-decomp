#include <globaldefs.h>

extern int data_021075f4;

// Returns the registry of field objects. It holds 32 entry pointers from +0xc, and each entry
// owns the object at +0x18 that event scripts register into game entity slots 0xa0-0xbf -- the
// same range the field overlay advances as Object3D every frame. func_0203e524 searches it for the
// entry nearest a position, which is what a talk target would need. This same module loads
// "data/chara_sub/%s.chr" and the "talk_*" animation names; that directory holds box.chr as well as
// people, so field object is the safer word than NPC.
extern "C" ARM void* GetFieldObjectRegistry(void) {
    return &data_021075f4;
}
