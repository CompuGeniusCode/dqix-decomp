#include <globaldefs.h>

// USA: func_ov025_021e169c
ARM void ClearMatchingBytes_021e169c(unsigned char* p, int val) {
    for (int i = 0; i < 0x51; i++) {
        if (*p == val) {
            *p = 0;
        }
        p++;
    }
}
