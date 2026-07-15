#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" char* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d612c(void* obj);
extern char data_ov001_02165745;

// USA: func_ov001_021613d0
ARM int FormatFieldD8_021613d0(void* obj) {
    char* base = func_ov017_0218b5b0();
    char* p = *(char**)(base + 0x3000 + 0x734);
    int v = func_ov017_021d612c(obj);
    sprintf(p + 0xd8, &data_ov001_02165745, v);
    return 1;
}
