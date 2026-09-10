#include <globaldefs.h>

struct FlagOwner;

extern "C" void func_020e1cb8(struct FlagOwner* obj);
extern "C" void func_020e25cc(signed char* p);

struct Obj020e25e8 {
    char pad[0x10];
    struct FlagOwner* owner;
};

// Puts a menu prompt back to its resting state - the confirmed choice at +0x15 goes to -1, +0x14 is
// reloaded from +0x16, +0x17 is zeroed, and the owner's flag byte loses bit 1 and gains bit 2. That
// +0x15 holds the choice is visible in func_020e2918, which func_ov003_0215bf18 polls
// until it returns a non-negative entry and then calls this. func_020e2834 shares
// the struct and lights one of two palette entries by +0x14, so +0x14 is the current choice and
// +0x16 its default. All 21 callers are menu overlays: shisetsu, topmenu, equipmenu and renkin.
extern "C" ARM void ResetMenuSelection(struct Obj020e25e8* obj) {
    func_020e1cb8(obj->owner);
    func_020e25cc((signed char*)obj);
}
