#include <globaldefs.h>

// USA: func_ov000_0215fa70
ARM void SetShortFields0x8e4aTo0x8e4e(void* obj, int a, int b, int c) {
    *(short*)((char*)obj + 0x8e4a) = (short)a;
    *(short*)((char*)obj + 0x8e4c) = (short)b;
    *(short*)((char*)obj + 0x8e4e) = (short)c;
}
