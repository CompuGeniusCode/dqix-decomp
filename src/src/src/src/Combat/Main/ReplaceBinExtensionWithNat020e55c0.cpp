#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_02003ce8(char* dst, const char* fmt, ...);
extern const char data_020f2e20[];
extern const char data_020f2e25[];

// USA: func_020e55c0
ARM int ReplaceBinExtensionWithNat020e55c0(char* dst, const char* fmt) {
    if (!dst || !fmt) return 0;
    func_02003ce8(dst, fmt);
    char* p = strstr(dst, data_020f2e20);
    if (p) strcpy(p, data_020f2e25);
    return 1;
}
