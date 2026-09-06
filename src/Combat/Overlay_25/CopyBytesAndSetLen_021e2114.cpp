#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020c9be0(void);

// USA: func_ov025_021e2114
ARM void CopyBytesAndSetLen_021e2114(unsigned char* dst, void* src, int count) {
    if (count > 0xc) {
        func_020c9be0();
    }
    memcpy(dst+8, src, count);
    dst[0x14] = (unsigned char)count;
}
