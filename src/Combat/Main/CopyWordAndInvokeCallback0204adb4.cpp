#include <globaldefs.h>
#include "std_library_functions.h"

typedef void (*Callback0204adb4)(void*, int, int);

// USA: func_0204adb4
ARM void CopyWordAndInvokeCallback0204adb4(unsigned char* dst, Callback0204adb4 callback, unsigned char* src) {
    memcpy(dst + 0x8, src + 0xc, 4);
    callback(src + 0x10, 0, *(int*)(dst + 0x8));
}
