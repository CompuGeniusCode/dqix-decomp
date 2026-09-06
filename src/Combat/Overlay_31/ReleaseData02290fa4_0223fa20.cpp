#include <globaldefs.h>

extern int data_ov031_02290fa4;
struct RefNode020c80f8;
extern "C" void _Z11UnlockMutexP5Mutex(RefNode020c80f8 *node);

// USA: func_ov031_0223fa20
ARM void ReleaseData02290fa4_0223fa20(void) {
    _Z11UnlockMutexP5Mutex((RefNode020c80f8*)&data_ov031_02290fa4);
}
