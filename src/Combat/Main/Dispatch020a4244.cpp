#include <globaldefs.h>

extern "C" int func_020a3d68(int, void*, void*);

// USA: func_020a4244
ARM int Dispatch020a4244(char* a, int b) {
    return func_020a3d68(b, a + 0x6c, a);
}
