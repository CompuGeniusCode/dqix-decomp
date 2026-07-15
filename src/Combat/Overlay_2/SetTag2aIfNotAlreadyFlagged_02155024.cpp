#include <globaldefs.h>

// USA: func_ov002_02155024
ARM void SetTag2aIfNotAlreadyFlagged_02155024(unsigned char* obj) {
    if (obj[0x2000 + 0x48f] == 0 && obj[0x2000 + 0x48e] == 0) {
        obj[0x2000 + 0x48e] = 1;
        obj = obj + 0x1000;
        *(int*)(obj + 0xbb8) = 0x2a;
        *(int*)(obj + 0xbc0) = 0;
    }
}
