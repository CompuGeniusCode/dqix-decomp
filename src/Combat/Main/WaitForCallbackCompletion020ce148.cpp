#include <globaldefs.h>

struct LockState020ce148 {
    unsigned char pad[0x1c];
    int lock;
};
extern struct LockState020ce148 data_021117ec;
extern int data_02111808;
int GetProcessorMode(void);
void HandleCommandReceivedFromArm7(void);

// USA: func_020ce148
ARM void WaitForCallbackCompletion020ce148(void) {
    struct LockState020ce148* lockState = &data_021117ec;
    int* counter = &data_02111808;
    if (lockState->lock == 0) {
        return;
    }
    do {
        if (GetProcessorMode() == 0x12) {
            HandleCommandReceivedFromArm7();
        }
    } while (*counter != 0);
}
