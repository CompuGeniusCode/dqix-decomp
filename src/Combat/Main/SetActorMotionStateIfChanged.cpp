#include <globaldefs.h>

extern "C" void func_02033ce8(void*);

struct Obj02033b68 {
    char pad[0xbe];
    unsigned char fbe;
    unsigned char fbf;
};

// The curated SetActorMotionState at 0x02033b88 without the redundant work: push the old motion
// state at +0xbe down into +0xbf, store the new one, then let func_02033ce8 react - but return
// early when the value has not changed, so func_02033ce8 only runs on a real transition.
// func_02033b58 is the third form, the same shift with no notify at all.
extern "C" ARM void SetActorMotionStateIfChanged(struct Obj02033b68* obj, int newVal) {
    if (obj->fbe == newVal) return;
    obj->fbf = obj->fbe;
    obj->fbe = newVal;
    func_02033ce8(obj);
}
