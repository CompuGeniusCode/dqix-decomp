#include <globaldefs.h>

extern "C" void func_020c9be0(void);
void SpinDrainAfterWait(void);

struct ShutdownGuard020d18d0 {
    int _pad0[3];          /* 0x0,0x4,0x8 */
    int done;              /* 0xc */
    int _pad1[2];          /* 0x10,0x14 */
    int (*callback)(void); /* 0x18 */
};
extern ShutdownGuard020d18d0 data_02112160;

// USA: func_020d18d0
ARM void DispatchType0x11ShutdownOnce(int context, int code) {
    if ((code & 0x3f) == 0x11) {
        if (data_02112160.done != 0) return;
        {
            int (*cb)(void) = data_02112160.callback;
            int r = 0;
            if (cb != 0) r = cb();
            if (r != 0) SpinDrainAfterWait();
        }
        data_02112160.done = 1;
        return;
    }
    func_020c9be0();
}
