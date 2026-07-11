#include <globaldefs.h>

struct LockState020ce148 {
    unsigned char pad[0x1c];
    int lock;
};
extern struct LockState020ce148 data_021117ec;
extern int data_02111808;
extern "C" int func_020c9760(void);
extern "C" void func_020caf1c(void);

// USA: func_020ce148
ARM void WaitForCallbackCompletion020ce148(void) {
    struct LockState020ce148* lockState = &data_021117ec;
    int* counter = &data_02111808;
    if (lockState->lock == 0) {
        return;
    }
    do {
        if (func_020c9760() == 0x12) {
            func_020caf1c();
        }
    } while (*counter != 0);
}
