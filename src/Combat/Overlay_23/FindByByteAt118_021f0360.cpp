#include <globaldefs.h>

// USA: func_ov023_021f0360
ARM void* FindByByteAt118_021f0360(void* base, int val) {
    unsigned char* p = (unsigned char*)base + 0x118;
    int i;
    for (i = 0; i < *((unsigned char*)base + 0x2788); i++) {
        if (*p == val) {
            return p;
        }
        p += 0x19c + 0x800;
    }
    return 0;
}
