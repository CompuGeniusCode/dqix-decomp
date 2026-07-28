#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_0218b5b0(void);

// USA: func_ov003_02160344  (semantic: FormatEntriesFromBase_02160344)
extern "C" ARM void func_ov003_02160344(char* obj) {
    char* base = (char*)func_ov017_0218b5b0() + 0x35c;
    int i = 0;
    base = base + 0x4000;
    for (; i < 4; i++) {
        int* arr = *(int**)(obj + 0x394);
        if (arr == 0) return;
        int val = arr[i];
        if (val == 0) continue;
        char* dest = base + i * 0x30;
        if (dest != 0) {
            sprintf(dest, (const char*)val);
        }
    }
}
