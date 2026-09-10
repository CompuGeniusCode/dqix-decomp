#include <globaldefs.h>

extern "C" void CancelBackgroundLoadTasks(int a);
extern "C" void func_ov017_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);

extern "C" int func_02094a00(void);
extern "C" int GetMessageWork(void);
extern "C" void ResetMessageDisplayState(char* obj);

struct ResetObj020d7a5c;
extern "C" void func_020d7a5c(struct ResetObj020d7a5c* o);

struct Flags020d7aa0 {
    unsigned char lo : 6;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

struct Obj020d7aa0 {
    unsigned char pad[0x150];
    struct Flags020d7aa0 flags;
};

// Empties the static message queue at data_0214e34c and unwinds what putting a message up cost:
// bit 7 means loader tasks are still outstanding on the data_02109400 object, bit 6 that the message
// display was in use, so ResetMessageDisplayState runs on the work GetMessageWork returns, and the
// two ov017 calls put the four-bit masks at +0x55d and +0x55e of the gamemain object back to
// all-set. func_020d7a5c is the plain clear; releasing those first is what this one adds. Every
// caller hands it GetPendingMessageQueue(), on teardown paths -- allocator destroyed, state reset.
extern "C" ARM void ClearPendingMessageQueue(struct Obj020d7aa0* obj) {
    int g = func_02094a00();
    if (obj->flags.bit7) {
        CancelBackgroundLoadTasks(g);
    }
    if (obj->flags.bit6) {
        ResetMessageDisplayState((char*)GetMessageWork());
        obj->flags.bit6 = 0;
    }
    func_ov017_0218b5c0(1, -1);
    func_ov017_0218b5f8(-1);
    func_020d7a5c((struct ResetObj020d7a5c*)obj);
}
