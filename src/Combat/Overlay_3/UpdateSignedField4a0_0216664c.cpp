#include <globaldefs.h>

extern "C" void func_ov003_021666c4(void* self);

// USA: func_ov003_0216664c
ARM void UpdateSignedField4a0_0216664c(void* self) {
    int flags = *(int*)((char*)self + 0x45c);
    int changed = 0;
    if (flags & 0x10) {
        signed char v = *((signed char*)self + 0x4a0);
        changed = 1;
        *((signed char*)self + 0x4a0) = v + 1;
    } else if (flags & 0x20) {
        signed char v = *((signed char*)self + 0x4a0);
        changed = 1;
        *((signed char*)self + 0x4a0) = v - 1;
    }
    signed char v = *((signed char*)self + 0x4a0);
    if (v >= 2) {
        *((signed char*)self + 0x4a0) = 0;
    } else if (v < 0) {
        *((signed char*)self + 0x4a0) = 1;
    }
    if (changed) {
        func_ov003_021666c4(self);
    }
}
