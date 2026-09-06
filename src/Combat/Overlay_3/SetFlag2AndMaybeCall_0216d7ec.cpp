#include <globaldefs.h>

extern "C" void func_ov003_0215caa4(void* p);

// USA: func_ov003_0216d7ec
ARM void SetFlag2AndMaybeCall_0216d7ec(char* obj) {
    *(unsigned char*)(obj + 0x1000 + 0x3ec) |= 2;
    short val = *(short*)(obj + 0x4);
    if (val == 3) {
        func_ov003_0215caa4(obj + 0x14);
    }
}
