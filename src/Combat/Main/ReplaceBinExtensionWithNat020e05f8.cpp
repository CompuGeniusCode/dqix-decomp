#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_02003ce8(char* dst, const char* fmt, ...);
extern const char data_020f2b6c[];
extern const char data_020f2b71[];

// USA: func_020e05f8
ARM int ReplaceBinExtensionWithNat020e05f8(char* dst, const char* fmt) {
    if (!dst || !fmt) return 0;
    func_02003ce8(dst, fmt);
    char* p = strstr(dst, data_020f2b6c);
    if (p) strcpy(p, data_020f2b71);
    return 1;
}
