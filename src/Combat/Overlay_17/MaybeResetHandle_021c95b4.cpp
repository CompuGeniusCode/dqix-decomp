#include <globaldefs.h>

extern "C" int func_ov017_021d446c(void* obj, void* out, int flags);
extern "C" void func_02076a8c(void* obj);
extern void SetFlag0x6cBit0(unsigned char* obj);

// USA: func_ov017_021c95b4
ARM void MaybeResetHandle_021c95b4(int unused, unsigned char* obj) {
    int local[3];
    if (func_ov017_021d446c(obj + 4, local, -1)) {
        func_02076a8c((void*)local[2]);
        SetFlag0x6cBit0((unsigned char*)local[2]);
    }
}
