#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_020696bc(char* str, int* out, int count);
int GetGlobalField0x1c020421a0(void);

// USA: func_020699c4
ARM int ParseAndStoreThreeFields020699c4(int* ctx, char* str) {
    int parsed[3];
    func_020696bc(str, parsed, 3);
    char* base = (char*)GetGlobalField0x1c020421a0();
    unsigned short v2 = (unsigned short)parsed[2];
    int b1 = parsed[1] != 0;
    int b0 = parsed[0] != 0;
    base[0x19c6] = (unsigned char)b0;
    base[0x19c7] = (unsigned char)b1;
    *(unsigned short*)(base + 0x187e) = v2;
    unsigned short tmp = 0xff1b;
    memcpy((void*)ctx[0], &tmp, 2);
    return 2;
}
