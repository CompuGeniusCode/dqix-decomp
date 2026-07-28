#include <globaldefs.h>

extern "C" void func_020301c8(int, int);
int GetData02104304Field4();

// USA: func_ov023_021e61a0  (semantic: ClearFieldTableAndDispatch_021e61a0)
extern "C" ARM void func_ov023_021e61a0(void* obj) {
    int listPtr = GetData02104304Field4();
    for (int i = 0; i < 0xc; i++) {
        if (*(short*)((char*)obj + (i << 1) + 0xb00 + 0xf4) > -1) {
            func_020301c8(listPtr, *(short*)((char*)obj + (i << 1) + 0xb00 + 0xf4));
        }
        *(short*)((char*)obj + (unsigned int)(i << 1) + 0xb00 + 0xf4) = -1;
    }
}
