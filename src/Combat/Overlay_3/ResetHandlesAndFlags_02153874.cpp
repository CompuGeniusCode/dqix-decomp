#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int a, int b);

// USA: func_ov003_02153874
ARM void ResetHandlesAndFlags_02153874(void* obj) {
    int v = GetData02104304Field4();
    if (*(int*)((char*)obj + 0x50) >= 0) {
        func_020301c8(v, *(int*)((char*)obj + 0x50));
    }
    if (*(int*)((char*)obj + 0x54) >= 0) {
        func_020301c8(v, *(int*)((char*)obj + 0x54));
    }
    *(int*)((char*)obj + 0x14) = 0;
    *(int*)((char*)obj + 0x10) = 0;
    *(int*)((char*)obj + 0x50) = -1;
    *(int*)((char*)obj + 0x54) = -1;
    *(unsigned char*)((char*)obj + 0x5a) = 2;
    *(unsigned char*)((char*)obj + 0x5b) = 0;
    *(unsigned char*)((char*)obj + 0x5c) = 0;
    *(unsigned char*)((char*)obj + 0x5d) &= ~2;
}
